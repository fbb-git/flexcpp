#include "statestring.ih"

StateData *StateString::v_clone() const
{
    return new StateString(d_str, next1(), next2());
}
