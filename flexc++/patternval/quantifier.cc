#include "patternval.ih"

PatternVal PatternVal::quantifier(States &states, PatternVal const &pat, 
                                                  size_t type)
{
    PatternVal ret;

    switch (type)
    {
        case '*':
            ret = star(states, pat);
        break;

        case '+':
            ret = plus(states, pat);
        break;

        case '?':
            ret = questionMark(states, pat);
        break;
    }

    return ret;
}
