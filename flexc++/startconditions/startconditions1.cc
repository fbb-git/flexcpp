#include "startconditions.ih"

StartConditions::StartConditions()
:
    d_type(EXCLUSIVE)
{
    d_hash["INITIAL"] = {INCLUSIVE};
}

