#include "startconditions.ih"

void StartConditions::activate(size_t index)
{
    d_active = std::vector<StartCondition *>(1, 
                                    &(d_sc.begin() + index)->second);
}


