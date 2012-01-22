#ifndef INCLUDED_SEMUNION_H_
#define INCLUDED_SEMUNION_H_

#include <memory>
#include <utility>
#include <string>
#include "../patternval/patternval.h"

namespace SemUnionNamespace
{
    template <int tp>
    struct TypeStruct;

    template <typename Type>
    struct Result;
}

class SemUnion
{
    std::pair<int, int>         d_index;
    std::pair<int, std::string> d_str;
    std::pair<int, PatternVal>  d_patternVal;

    public:
        enum Types
        {
            INT,
            STRING,
            PATTERNVAL,
        };

        SemUnion();
        SemUnion(std::string const &str);
        SemUnion(PatternVal const &pval);

        ~SemUnion();

        template <typename Type>
        typename SemUnionNamespace::Result<Type>::type const &value() const;

    private:
        operator std::string const &() const;
        operator PatternVal const &() const;
        
};

namespace SemUnionNamespace
{
    template <>
    struct Result<TypeStruct<SemUnion::STRING>>
    {
        typedef std::string type;
    };

    template <>
    struct Result<TypeStruct<SemUnion::PATTERNVAL>>
    {
        typedef PatternVal type;
    };
}

inline SemUnion::SemUnion()
{
    new (this) std::pair<int, int>(INT, 0);
}

inline SemUnion::SemUnion(std::string const &str)
{
    new (this) std::pair<int, std::string>(STRING, str);
}

inline SemUnion::SemUnion(PatternVal const &pv)
{
    new (this) std::pair<int, PatternVal>(PATTERNVAL, pv);
}

inline SemUnion::operator std::string const &() const
{
    return d_str.second;
}

inline SemUnion::operator PatternVal const &() const
{
    return d_patternVal.second;
}

template <typename Type>
typename SemUnionNamespace::Result<Type>::type const &SemUnion::value() const
{
    return static_cast
                <typename SemUnionNamespace::Result<Type>::type const &>
                (*this);
}

typedef std::shared_ptr<SemUnion> spSemUnion;
        
#endif





