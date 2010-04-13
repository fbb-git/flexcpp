#include "startconditions.ih"

StartConditions::StartConditions()
:
    d_type(EXCLUSIVE),
    d_inclusive(false)
{
    d_hash["INITIAL"] = {EXCLUSIVE};
}

