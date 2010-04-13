#include "patternval.ih"

spSemVal PatternVal::quantifier(States &states, SemVal &pat, size_t type)
{
    switch (type)
    {
        case '*':
        return star(states, pat);
    
        case '+':
        return plus(states, pat);
    
        case '?':
        return questionMark(states, pat);
    
        default:
        throw logic_error("PatternVal::quantifier received unexpected type");
    }
}
