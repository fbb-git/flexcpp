#include "patternval.ih"
#include <iostream>

spSemVal PatternVal::dot(States &states)
{
    spSemVal ret = charSet(states, *CharClass::predefined("."));
    return ret;
}
