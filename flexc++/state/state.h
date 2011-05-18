#ifndef INCLUDED_STATE_
#define INCLUDED_STATE_

#include <memory>
#include <iosfwd>

#include "../statedata/statedata.h"

class State
{
    typedef char Alphabet;

    public:
        enum Flag
        {
            NO_LOP,     // state not belonging to a LOP-rule (default)
            ACCEPT,     // the accept-state of a LOP-rule
            PRE,        // a pre-accept state of a LOP-rule
            POST        // a post-accept state of a LOP-rule
        };

        enum Type       // values in the Alphabet range are simple characters
        {
            UNDETERMINED__ =  1 << (8 * sizeof(Alphabet)),
            EMPTY,                              
            FINAL,
            CHARSET,                            // string contents of [ ... ]
            EOF__                               // EOF becomes a special char
        };                                      // see README

    private:
        std::shared_ptr<StateData> d_data;

        size_t d_type;      // if less than UNDETERMINED__: a simple character
                            // or character range value
        Flag d_flag;        // a Flags-value
        size_t d_rule;      // the rule this state refers to

    public:        
        State();
        explicit State(size_t type);
        State(size_t type, StateData *data);  // State will own the data

        static State factory(size_t type, size_t next1, size_t next2);
        static State factory(size_t type, std::string const &str, 
                                        size_t next1 = 0, size_t next2 = 0);
        static State factory(unsigned char ch, size_t next1);

        StateData &data();
        size_t next1() const;           // 0: no next state(s)
        size_t next2() const;

        StateData const &data() const;

        void setType(size_t type);      // change the char. type
        size_t type() const;            // if < UNDETERMINED__ it's a char

        void setRule(size_t idx);       // set the state's rule index
        size_t rule() const;

        void setFlag(Flag value);       // Set a State's flag
        Flag flag() const; 

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

inline size_t State::rule() const
{
    return d_rule;
}

inline State::Flag State::flag() const
{
    return d_flag;
}

inline void State::setFlag(Flag value)
{
    d_flag = value;
}

std::ostream &operator<<(std::ostream &out, State const &state);


#endif


