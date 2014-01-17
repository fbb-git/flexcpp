#include "pattern.ih"

Pattern Pattern::interval(States &states, Pattern &regex,
                                Interval const &interval)
{
    Pattern ret;

    size_t lower = interval.lower();
    size_t upper = interval.upper();

    if (lower == 0 && upper == numeric_limits<size_t>::max())
        ret = star(states, regex);

    else if (lower == 0 && upper == 1)
        ret = questionMark(states, regex);

    else if (lower == 1 && upper == numeric_limits<size_t>::max())
        ret = plus(states, regex);

    else if (lower <=  upper)
    {
        ret = copy(states, regex, lower, upper);
        if (lower == upper && regex.fixedLength())
            ret.d_length = lower * regex.d_length;
    }

    else
    {
        Pair pair = states.next2();
        states[pair.first] = State(EMPTY, pair.second, 0);

        ret = Pattern(pair);
    }
    return ret;
}






