#include "dfarow.hh"

bool DFARow::operator==(DFARow const &rhs) const
{
    return d_finalRule == rhs.d_finalRule && sameTransits(d_map, rhs.d_map);
}
