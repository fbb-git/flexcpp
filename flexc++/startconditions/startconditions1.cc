#include "startconditions.hh"

StartConditions::StartConditions()
:
    d_sc(
        {
            {"INITIAL", StartCondition(INCLUSIVE) } 
        } 
    )
{}

