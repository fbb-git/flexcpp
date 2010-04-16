#include "state.ih"

bool State::contains(size_t rangeChar) const
{
    return 
        SemVal::downCast<StateString>(*d_data).str().find(rangeChar) 
        != string::npos;
}