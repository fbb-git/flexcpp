#include "patternval.ih"

spSemVal PatternVal::interval(States &states, SemVal &semval, size_t lower, 
                                                              size_t upper)
{
    spSemVal ret;

    if (lower == 0 && upper == UINT_MAX)
        ret = star(states, semval);

    else if (lower == 0 && upper == 1)
        ret = questionMark(states, semval);

    else if (lower == 1 && upper == UINT_MAX)
        ret = plus(states, semval);

    else if (lower <=  upper)
        ret = copy(states, semval, lower, upper);

    else
    {
        States::Pair pair = states.next2();
        states[pair.first] = State::factory(State::EMPTY, pair.second, 0);

        ret.reset(new PatternVal(pair));
    }

    return ret;
}






