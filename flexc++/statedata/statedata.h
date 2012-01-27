#ifndef INCLUDED_STATEDATA_
#define INCLUDED_STATEDATA_

#include <string>
#include <cstddef>
#include <stdexcept>

class StateData
{
    size_t d_next1;         // 0: no next state(s)
    size_t d_next2;

    public:
        StateData(size_t next1, size_t next2);
        virtual ~StateData();

        StateData *dup() const;
        std::string const &str() const;

        size_t next1() const;
        size_t next2() const;
        void set(size_t next1, size_t next2 = 0);
        void set2nd(size_t next2);

        void set(std::string const &str);
        
    private:    
        void v_set(std::string const &str);
        virtual StateData *v_clone() const;
        virtual std::string const &v_str() const;
};

inline StateData *StateData::dup() const
{
    return v_clone();
}

inline std::string const &StateData::str() const
{
    return v_str();
}

inline std::string const &StateData::v_str() const
{
    static std::string ret;
    return ret;
}

inline void StateData::set(std::string const &str)
{
    v_set(str);
}

inline void StateData::v_set(std::string const &str)
{}

inline size_t StateData::next1() const
{
    return d_next1;
}
        
inline size_t StateData::next2() const
{
    return d_next2;
}
        
inline void StateData::set(size_t next1, size_t next2)
{
    d_next1 = next1;
    d_next2 = next2;
}
        
inline void StateData::set2nd(size_t next2)
{
    d_next2 = next2;
}
        
#endif

