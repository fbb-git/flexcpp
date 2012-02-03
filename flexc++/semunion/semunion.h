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
class SemUnion: public DataType
{
    Symbol d_index;

    union
    {
        std::string d_str;
        Pattern     d_pattern;
        CharClass   d_charClass;
        Interval    d_interval;
    };

    public:
        SemUnion();
        SemUnion(SemUnion const &other);        // 1

        template <typename Type>
        SemUnion(Type const &value);
    
        ~SemUnion();

        template <Symbol dataType>
        typename Type<Int<dataType>>::type &value();

        Symbol index() const;

    private:
        template <typename Type>
        Type const *conversion() const;
};

inline SemUnion::SemUnion()
:
    d_index(INT)
{}

inline DataType::Symbol SemUnion::index() const
{
    return d_index;
}

template <typename Tp>
inline SemUnion::SemUnion(Tp const &value)
:
    d_index(static_cast<Symbol>(Type<Tp>::dataType))
{
    new (&d_str) Tp(value);
}

template <typename Type>
inline Type const *SemUnion::conversion() const
{
    return reinterpret_cast<Type const *>(&d_str);
}

template <DataType::Symbol dataType>
inline typename Type<Int<dataType>>::type &SemUnion::value()
{
    return *const_cast<typename Type<Int<dataType>>::type *>(
                conversion<typename Type<Int<dataType>>::type>());
}
        
#endif





