#include "startconditions.ih"
    
void StartConditions::useAll()
{
    reset();

    for(auto &mini: d_sc)
        d_active.push_back(&mini.second);
}
