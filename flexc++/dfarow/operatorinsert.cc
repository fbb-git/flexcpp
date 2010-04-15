#include "dfarow.ih"

#include <ostream>

ostream &operator<<(ostream &out, DFARow const &row)
{
    for (size_t idx = 0; idx++ != row.d_nRanges; )
    {
        auto iter = row.d_map.find(idx);
        if (iter == row.d_map.end())
            out << ' ';
        else
            out << iter->second;
    }

    return out;
}
