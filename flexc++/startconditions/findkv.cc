#include "startconditions.ih"

StartConditions::KeyValue *StartConditions::findKV(string const &key) const
{
    return
        const_cast<KeyValue *>(
            &*std::find_if(d_scVector.begin(), d_scVector.end(), 
                [&](KeyValue const &entry)
                {
                    return entry.first == key;
                }
            )
        );
}
