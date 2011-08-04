#ifndef INCLUDED_STATESTRING_
#define INCLUDED_STATESTRING_

#include <string>

#include "../statedata/statedata.h"

class StateString: public StateData
{
    std::string d_str;
    
    public:
        StateString(std::string const &str, size_t next1, size_t next2);
        std::string const &str() const;
        void set(std::string const &str);

        virtual StateData *clone(size_t next1, size_t next2) const;
};

inline void StateString::set(std::string const &str)
{
    d_str = str;
}
        
inline std::string const &StateString::str() const
{
    return d_str;
}
        
        
#endif
