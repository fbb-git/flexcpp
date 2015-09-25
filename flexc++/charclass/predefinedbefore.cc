#include "charclass.ih"

bool CharClass::predefinedBefore(size_t idx) const
{
    if (isPredefined(idx - 1))            // predefined range before '-' ?
    {
        emsg << "'-' cannot follow predefined set" << endl;
        return true;
    }

    return false;
}
