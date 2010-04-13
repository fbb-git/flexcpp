#ifndef INCLUDED_DECIMAL_
#define INCLUDED_DECIMAL_

#include "../semval/semval.h"

class Decimal: public SemVal
{
    size_t d_lower;
    size_t d_upper;

    public:
        Decimal(Decimal const &other) = delete;

        static spSemVal exact(std::string const &str);
        static spSemVal range(SemVal &lower, SemVal &upper);
        static spSemVal lowerBound(SemVal &lower);

        size_t lower() const;
        size_t upper() const;

    private:
        Decimal(size_t lower, size_t upper);        
};

inline size_t Decimal::lower() const
{
    return d_lower;
}

inline size_t Decimal::upper() const
{
    return d_upper;
}

#endif
