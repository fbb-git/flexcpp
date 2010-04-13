#ifndef INCLUDED_STATES_
#define INCLUDED_STATES_

#include <vector>

#include "../state/state.h"

class States
{
    std::vector<State> d_state;
    std::vector<size_t> d_free;

    public:
        typedef std::pair<size_t, size_t> Pair;

        States();
        State &operator[](size_t idx);
        size_t next();
        Pair next2();                       // 2nd initialized to FINAL
        void collect(size_t idx);

        std::vector<State>::const_iterator begin() const;
        std::vector<State>::const_iterator end() const;
};

inline State &States::operator[](size_t idx)
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

inline void States::collect(size_t idx)
{
    return d_free.push_back(idx);
}

#endif



