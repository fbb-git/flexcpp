#include "statestring.ih"

StateData *StateString::clone(size_t next1, size_t next2) const
{
    return new StateString(d_str, next1, next2);
}
