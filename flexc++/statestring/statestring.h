#ifndef INCLUDED_STATESTRING_
#define INCLUDED_STATESTRING_

#include "../statedata/statedata.h"

class StateString: public StateData
{
    std::string d_str;
    
    public:
        StateString(std::string const &str, size_t next1, size_t next2);

    private:
        void v_set(std::string const &str);
        std::string const &v_str() const;
        virtual StateData *v_clone() const;
};

inline void StateString::v_set(std::string const &str)
{
    d_str = str;
}
        
inline std::string const &StateString::v_str() const
{
    return d_str;
}
        
        
#endif

