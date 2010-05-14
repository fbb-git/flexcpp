#ifndef INCLUDED_STATES_
#define INCLUDED_STATES_

#include <algorithm>

#include <iosfwd>
#include <vector>
#include <set>

#include "../state/state.h"

class States
{
    std::vector<State> d_state;
    std::vector<size_t> d_free;

    public:
        typedef std::pair<size_t, size_t> Pair;

        States();
        State &operator[](size_t idx);
        State const &operator[](size_t idx) const;
        size_t next();
        Pair next2();                       // 2nd initialized to FINAL
        size_t *next(size_t nStates);       // returned memory owned by caller
                                            // returns nStates indices to use
                                            // in d_state.
        void collect(size_t idx);

        std::vector<State>::const_iterator begin() const;
        std::vector<State>::const_iterator end() const;
        std::vector<State>::iterator begin();
        std::vector<State>::iterator end();

        std::set<size_t> eClosure(std::set<size_t> &current) const;
        size_t size() const;
};

inline State &States::operator[](size_t idx)
{
    return d_state[idx];
}

inline State const &States::operator[](size_t idx) const
{
    return d_state[idx];
}

inline std::vector<State>::const_iterator States::begin() const
{
    return d_state.begin();
}

inline std::vector<State>::const_iterator States::end() const
{
    return d_state.end();
}

inline std::vector<State>::iterator States::begin()
{
    return d_state.begin();
}

inline std::vector<State>::iterator States::end() 
{
    return d_state.end();
}

inline size_t States::size() const
{
    return d_state.size();
}

std::ostream &operator<<(std::ostream &out, States const &states);


#endif



