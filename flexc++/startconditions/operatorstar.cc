#include "startconditions.ih"

StartConditions::NameVector 
                    const &StartConditions::const_iterator::operator*() const
{
    d_nameVector = {(*d_iter).first, (*d_iter).second.d_rules};
    return d_nameVector;
}
