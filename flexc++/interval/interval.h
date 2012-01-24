#ifndef INCLUDED_INTERVAL_
#define INCLUDED_INTERVAL_

#include <string>

#include "../utility/utility.h"

class Interval: private std::pair<size_t, size_t>
{
    size_t d_lower;
    size_t d_upper;

    public:
        static Interval exact(std::string const &str);
        static Interval range(std::string const &lower, 
                              std::string const &upper);
        static Interval lowerBound(std::string const &lower);

    private:
        Interval(size_t lower, size_t upper);        

};
        
#endif
