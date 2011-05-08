#include "dfarow.ih"

void DFARow::keepViableAccCounts(DFARow &dfaRow)
{
    for 
    (
        auto iter = dfaRow.d_accCount.begin(); 
            iter != dfaRow.d_accCount.end(); 
                // no increment here
    )
    {
        if (not (*dfaRow.d_rules)[iter->rule()].viable())
            iter = dfaRow.d_accCount.erase(iter);
        else
            ++iter;
    }
}
