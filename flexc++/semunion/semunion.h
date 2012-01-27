#ifndef INCLUDED_SEMUNION_H_
#define INCLUDED_SEMUNION_H_

#include <memory>
#include <utility>
#include <string>

#include "../pattern/pattern.h"
#include "../charclass/charclass.h"
#include "../interval/interval.h"

template <>
struct Type<std::string>                        // define 'DataType'
{                                               // given string
    enum { dataType = DataType::TEXT };
};

template <>                                     // defining 'string'
struct Type<Int<DataType::TEXT>>                // given TEXT
{
    typedef std::string type;
};

// To add a new union member:
//      - add an enum value to utility.h for the new data type
//      - the new member's class must define two Type specializations like
//          the ones just given for TEXT 
//      - add a field for the new type
//      - add the field's destructor call to ~SemUnion
union SemUnion
{
    std::pair<int, int>         d_index;
    std::pair<int, std::string> d_str;
    std::pair<int, Pattern>  d_patternVal;
    std::pair<int, CharClass>   d_charClass;
    std::pair<int, Interval>    d_interval;

    public:
        SemUnion();
        SemUnion(SemUnion const &other);        // 1

        template <typename Type>
        SemUnion(Type const &value);
    
        ~SemUnion();

        template <int dataType>
        typename Type<Int<dataType>>::type const &value() const;

        template <int dataType>
        typename Type<Int<dataType>>::type &value();

        int index() const;

    private:
        template <typename Type>
        Type &conversion() const;
};

inline SemUnion::SemUnion()
{
    new (this) std::pair<int, int>(DataType::INT, 0);
}

inline int SemUnion::index() const
{
    return d_index.first;
}

template <typename Tp>
inline SemUnion::SemUnion(Tp const &value)
{
    new (this) std::pair<int, Tp>(Type<Tp>::dataType, value);
}

template <typename Type>
inline Type &SemUnion::conversion() const
{
    int *ip = const_cast<int *>(&d_index.second);
    return *reinterpret_cast<Type *>(ip);
}

template <int type>
inline typename Type<Int<type>>::type const &SemUnion::value() const
{
    return conversion<typename Type<Int<type>>::type>();
}

template <int dataType>
inline typename Type<Int<dataType>>::type &SemUnion::value()
{
    return conversion<typename Type<Int<dataType>>::type>();
}
        
#endif





