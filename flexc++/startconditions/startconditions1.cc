#include "startconditions.ih"

StartConditions::StartConditions()
:
    d_scVector(1, KeyValue("INITIAL", {INCLUSIVE})),
    d_endUserStartConditions(d_scVector.end()),
{}

