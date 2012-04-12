#include "pattern.ih"

Pattern Pattern::quantifier(States &states, Pattern const &pat, 
                                                  size_t type)
{
    Options::regexCall("quantifier");

    Pattern ret;

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
