#include "startconditions.ih"

StartConditions::StartConditions()
:
    d_sc(
        {
            {"INITIAL", StartCondition(INCLUSIVE) } 
        } 
    )
{}

