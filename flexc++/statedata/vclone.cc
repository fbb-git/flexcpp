#include "statedata.ih"

StateData *StateData::v_clone() const
{
    return new StateData(d_next1, d_next2);
}
