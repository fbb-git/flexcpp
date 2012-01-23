#include "patternval.ih"

PatternVal PatternVal::alternatives(States &states, 
                                    PatternVal const &lhs, 
                                    PatternVal const &rhs)
{
    States::Pair pair = states.next2();
    states[pair.first] = State::factory(State::EMPTY, lhs.begin(), 
                                                      rhs.begin());

    states[lhs.end()] = State::factory(State::EMPTY, pair.second, 0);
    states[rhs.end()] = State::factory(State::EMPTY, pair.second, 0);

    PatternVal ret(pair);

    return ret;
}



