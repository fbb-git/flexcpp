#include "dfarow.ih"

void DFARow::mergeFinalSet(DFARow &row)
{
    for_each(row.d_finalRule.begin(), row.d_finalRule.end(), 
             FnWrap::unary(mergeFinal, row.d_finAcInfo));
}
