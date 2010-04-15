#include "dfarow.ih"

void DFARow::tabulate(Table &table) const
{
    for (size_t idx = 0; idx++ != d_nRanges; )
    {
        auto iter = d_map.find(idx);
        if (iter == d_map.end())
            table << ' ';
        else
            table << iter->second;
    }
}
