#include "dfarow.ih"

void DFARow::tabulateTransitions(Table &table) const
{
                                    // only display the ranges that are used 
     for (size_t idx = 0, end = d_ranges->nRanges(); idx++ != end; )
     {
         if (not d_ranges->usedRange(idx))
             continue;
 
         auto iter = d_map.find(idx);
         if (iter == d_map.end())
             table << ' ';
         else
             table << iter->second;
     }
}








