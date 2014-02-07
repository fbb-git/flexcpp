#include "charclass.ih"

bool CharClass::predefinedAfter(size_t idx) const
{
    if (isPredefined(idx + 1))            // predefined range beyond '-' ?
    {
        emsg << "predefined set cannot follow '-'" << endl;
        return true;
    }

    return false;
}
