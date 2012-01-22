#include "statedata.ih"

StateData *StateData::clone(size_t next1, size_t next2) const
{
    return new StateData(next1, next2);
}
