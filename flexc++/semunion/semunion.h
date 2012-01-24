#ifndef INCLUDED_SEMUNION_H_
#define INCLUDED_SEMUNION_H_

#include <memory>
#include <utility>
#include <string>

#include "../utility/utility.h"
#include "../patternval/patternval.h"
#include "../charclass/charclass.h"

template <int tp>
struct TypeStruct;

template <typename Type>
struct Result: public DataType
{};

union SemUnion
{
    std::pair<int, int>         d_index;
    std::pair<int, std::string> d_str;
    std::pair<int, PatternVal>  d_patternVal;
    std::pair<int, CharClass>   d_charClass;

    public:
        SemUnion();
        SemUnion(SemUnion const &other);        // 1
        SemUnion(std::string const &str);
        SemUnion(PatternVal const &pval);
        SemUnion(CharClass const &cval);

        ~SemUnion();

        template <int type>
        typename Result<TypeStruct<type>>::type const &value() const;

        template <int type>
        typename Result<TypeStruct<type>>::type &value();

    private:
        operator std::string &() const;
        operator PatternVal &() const;
        operator CharClass &() const;
        
};

inline SemUnion::SemUnion()
{
    new (this) std::pair<int, int>(DataType::INT, 0);
}

template <>
struct Result<TypeStruct<DataType::TEXT>>
{
    typedef std::string type;
};

inline SemUnion::SemUnion(std::string const &str)
{
    new (&d_str) std::pair<int, std::string>(DataType::TEXT, str);
}

inline SemUnion::operator std::string &() const
{
    return const_cast<std::string &>(d_str.second);
}


template <>
struct Result<TypeStruct<DataType::PATTERNVAL>>
{
    typedef PatternVal type;
};

inline SemUnion::SemUnion(PatternVal const &pv)
{
    new (&d_patternVal) std::pair<int, PatternVal>(DataType::PATTERNVAL, pv);
}

inline SemUnion::operator PatternVal &() const
{
    return const_cast<PatternVal &>(d_patternVal.second);
}


template <>
struct Result<TypeStruct<DataType::CHARCLASS>>
{
    typedef CharClass type;
};

inline SemUnion::SemUnion(CharClass const &cc)
{
    new (&d_charClass) std::pair<int, CharClass>(DataType::CHARCLASS, cc);
}

inline SemUnion::operator CharClass &() const
{
    return const_cast<CharClass &>(d_charClass.second);
}


template <int type>
inline typename Result<TypeStruct<type>>::type const &SemUnion::value() const
{
    return *this;
}

template <int type>
inline typename Result<TypeStruct<type>>::type &SemUnion::value()
{
    return *this;
}
        
#endif





