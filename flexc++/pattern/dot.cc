#include "pattern.ih"

Pattern Pattern::dot(States &states)
{
    Pattern ret = characterClass(states, CharClass::predefined("."));
    return ret;
}
