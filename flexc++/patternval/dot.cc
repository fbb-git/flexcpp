#include "patternval.ih"

spSemVal PatternVal::dot(States &states)
{
    spSemVal ret = charSet(states, *CharClass::predefined("."));
    return ret;
}
