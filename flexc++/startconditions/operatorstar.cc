#include "startconditions.ih"

StartConditions::NameVector StartConditions::const_iterator::operator*() const
{
    NameVector ret {(*d_iter).first, (*d_iter).second.d_rules};
    return ret;
}
