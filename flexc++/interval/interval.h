#ifndef INCLUDED_INTERVAL_
#define INCLUDED_INTERVAL_

#include <string>
#include "../utility/utility.h"

class Interval: private std::pair<size_t, size_t>
{
    size_t d_lower;
    size_t d_upper;

    public:
        Interval() = default;

        static Interval exact(std::string const &str);
        static Interval range(std::string const &lower, 
                              std::string const &upper);
        static Interval lowerBound(std::string const &lower);

        size_t lower() const;
        size_t upper() const;

    private:
        Interval(size_t lower, size_t upper);        

};

template <>                                     // two specializations:
struct Type<Interval>                         // defining 'DataType'
{                                               // given Interval
    enum { dataType = DataType::INTERVAL };
};

template <>                                     // defining 'Interval'
struct Type<Int<DataType::INTERVAL>>          // given INTERVAL
{
    typedef Interval type;
};

  
inline Interval::Interval(size_t lower, size_t upper)
:
    d_lower(lower),
    d_upper(upper)
{}

inline size_t Interval::lower() const
{
    return d_lower;
}

inline size_t Interval::upper() const
{
    return d_upper;
}

#endif
