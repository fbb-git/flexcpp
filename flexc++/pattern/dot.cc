#include "pattern.ih"

Pattern Pattern::dot(States &states)
{
    Pattern ret = characterClass(states, CharClass::predefined("."));
    ret.d_length = 1;
    return ret;
}
