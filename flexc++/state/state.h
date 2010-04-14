#ifndef INCLUDED_STATE_
#define INCLUDED_STATE_

#include <memory>
#include <iosfwd>

#include "../statedata/statedata.h"

class State
{
    typedef char Alphabet;

    size_t d_type;
    std::shared_ptr<StateData> d_data;

    public:
        enum Type       // values in the Alphabet range are simple character
        {
            UNDETERMINED__ =  1 << (8 * sizeof(Alphabet)),
            ACCEPT         =  UNDETERMINED__ << 1,  // use as flag

            EMPTY          =  ACCEPT << 1,      // use as values
            FINAL,
            BOL,                                // begin of line
            CHARSET,                            // string contents of [ ... ]
            EOF__
        };

        State();
        explicit State(size_t type);
        State(size_t type, StateData *data);  // State will own the data

        static State factory(size_t type, size_t next1, size_t next2);
        static State factory(size_t type, std::string const &str, 
                                        size_t next1 = 0, size_t next2 = 0);
        static State factory(unsigned char ch, size_t next1);

        StateData &data();
        StateData const &data() const;
        size_t type() const;            // if < UNDETERMINED__ it's a char
        void setType(size_t type);      // change the char. type, keep ACCEPT
        void setAccept();               // flag a State as an ACCEPT state
        bool accept() const;            // true if accepting state
};
        
inline StateData &State::data()
{
    return *d_data;
}

inline StateData const &State::data() const
{
    return *d_data;
}

inline size_t State::type() const
{
    return d_type & ~ACCEPT;
}

inline bool State::accept() const
{
    return d_type & ACCEPT;
}

inline void State::setAccept()
{
    d_type |= ACCEPT;
}

inline void State::setType(size_t type)
{
    d_type = type | (d_type & ACCEPT);
}

#endif


