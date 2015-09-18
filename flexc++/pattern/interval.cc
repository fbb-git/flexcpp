#include "pattern.hh"

Pattern Pattern::interval(States &states, Pattern &regex,
                                Interval const &interval)
{
    Pattern ret;

    size_t lower = interval.lower();
    size_t upper = interval.upper();

    if (lower == 0)
    {
        switch (upper)
        {
            case 0:
                wmsg << "ignoring regex{0, 0}" << endl;
            return regex;

            case 1:
                ret = questionMark(states, regex);
            break;

            case numeric_limits<size_t>::max():
                ret = star(states, regex);
            break;

            default:        // {0, x}, with 1 < x < size_t::max
            {
                Interval oneUp(1, upper);
                
                Pattern tmp = Pattern::interval(states, regex, oneUp);
                ret = questionMark(states, tmp);
            }                                
            break;
        }
    }

    else if (lower == 1 && upper == max<size_t>())
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






