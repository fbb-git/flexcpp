#ifndef INCLUDED_STATE_
#define INCLUDED_STATE_

#include <memory>
#include <iosfwd>

#include "../statedata/statedata.h"

class State
{
    typedef char Alphabet;

    std::shared_ptr<StateData> d_data;

    size_t d_type;      // below UNDETERMINED__: a simple character or 
                        // character range value

    int d_accept;       // -1: pre-accept state
    int d_rule;         // -1: not an LA rule, rule index irrelevant

    public:
        enum Type       // values in the Alphabet range are simple characters
        {
            UNDETERMINED__ =  1 << (8 * sizeof(Alphabet)),
            EMPTY,                              
            FINAL,
            CHARSET,                            // string contents of [ ... ]

            BOL,                                // begin of line and
            EOF__                               // EOF become special chars
        };                                      // see README
        
        State();
        explicit State(size_t type);
        State(size_t type, StateData *data);  // State will own the data

        static State factory(size_t type, size_t next1, size_t next2);
        static State factory(size_t type, std::string const &str, 
                                        size_t next1 = 0, size_t next2 = 0);
        static State factory(unsigned char ch, size_t next1);

        StateData &data();
        size_t next1() const;
        size_t next2() const;

        StateData const &data() const;

        void setType(size_t type);      // change the char. type
        size_t type() const;            // if < UNDETERMINED__ it's a char

        void setRule(size_t idx);       // set the state's rule index
        int rule() const;

        void setAccept(int value);      // Set a State's Accept type
        int accept() const;             // return Accept value

//        void nextAccept();      

            // true is returned if the state's string contains rangeChar.
            // Only defined for d_type == CHARSET
        bool contains(size_t rangeChar) const;
};
        
inline StateData &State::data()
{
    return *d_data;
}

inline StateData const &State::data() const
{
    return *d_data;
}

inline size_t State::next1() const
{
    return d_data->next1();
}

inline size_t State::next2() const
{
    return d_data->next2();
}

inline size_t State::type() const
{
    return d_type;
}

inline void State::setType(size_t type)
{
    d_type = type;
}

inline void State::setRule(size_t index)
{
    d_rule = index;
}

inline int State::rule() const
{
    return d_rule;
}

inline int State::accept() const
{
    return d_accept;
}

inline void State::setAccept(int value)
{
    d_accept = value;
}

std::ostream &operator<<(std::ostream &out, State const &state);


#endif


