#include "patternval.ih"

PatternVal PatternVal::interval(States &states, PatternVal &regex,
                                Interval const &interval)
{
    PatternVal ret;

    size_t lower = interval.lower();
    size_t upper = interval.upper();

    if (lower == 0 && upper == numeric_limits<size_t>::max())
        ret = star(states, regex);

    else if (lower == 0 && upper == 1)
        ret = questionMark(states, regex);

    else if (lower == 1 && upper == numeric_limits<size_t>::max())
        ret = plus(states, regex);

    else if (lower <=  upper)
        ret = copy(states, regex, lower, upper);

    else
    {
        States::Pair pair = states.next2();
        states[pair.first] = State::factory(State::EMPTY, pair.second, 0);

        ret = PatternVal(pair);
    }

    return ret;
}






