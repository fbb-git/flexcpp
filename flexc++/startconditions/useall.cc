#include "startconditions.ih"

    
void StartConditions::useAll()
{
    reset();

    for_each(
        d_hash.begin(), d_hash.end(), 
        [&](Hash::value_type &mini)
        {
            d_active.push_back(&mini.second);
        }
    );
}
