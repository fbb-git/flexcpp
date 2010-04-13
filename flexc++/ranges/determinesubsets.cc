#include "usage.ih"

void Usage::add(States const &states)
{
    for_each(states.begin(), states.end(), 
                FnWrap::unary(inspectState, *this));
}
