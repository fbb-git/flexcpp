#include "startconditions.ih"

StartConditions::SCVector::iterator StartConditions::find(string const &key) const
{
    SCVector::iterator ret(
        const_cast<KeyValue *>(&*std::find_if(d_scVector.begin(), d_scVector.end(), 
        [&](KeyValue const &entry)
        {
            return entry.first == key;
        }
    )));

    return ret;
}
