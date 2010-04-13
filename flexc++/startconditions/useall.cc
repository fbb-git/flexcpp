#include "startconditions.ih"

    
void StartConditions::useAll()
{
    reset();

    for_each(d_hash.begin(), d_hash.end(), 
             FnWrap::unary(addVector, d_active));
}
