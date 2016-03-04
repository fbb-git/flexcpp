#include "dfarow.ih"

void DFARow::tabulateTransitions(Table &table) const
{
                                    // only display the ranges that are used 
     for (size_t idx = 0; idx != d_nRanges; ++idx)
     {
         if (not (*d_usedRanges)[idx])
             continue;
 
         auto iter = d_map.find(idx);
         if (iter == d_map.end())
             table << ' ';
         else
             table << iter->second;
     }
}








