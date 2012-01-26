#include "pattern.ih"

Pattern Pattern::alternatives(States &states, 
                                    Pattern const &lhs, 
                                    Pattern const &rhs)
{
    States::Pair pair = states.next2();
    states[pair.first] = State::factory(State::EMPTY, lhs.begin(), 
                                                      rhs.begin());

    states[lhs.end()] = State::factory(State::EMPTY, pair.second, 0);
    states[rhs.end()] = State::factory(State::EMPTY, pair.second, 0);

    Pattern ret(pair);

    return ret;
}



