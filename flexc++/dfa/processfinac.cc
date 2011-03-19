#include "dfa.ih"

// This function visits all rules at dfa row 0
// 
// It calls processFinAcInfo that picks up the rule nr from the FinAcInfo object
// calling processRule to process the DFA for the current rule (for each rule
// using the LA operator this happends only once).
// 
// processRule checks whether the requested rule is available at the current
// DFA row and if so it calls processRule to set/inspect the FinAcInfo for the
// given rule at the given DFA row.
//
// processRule calls processRow to do the actual work, calling inspect for
// each transition.

void DFA::processFinAc()
{
    for_each(d_row[0].finAcInfos().begin(), d_row[0].finAcInfos().end(),
             FnWrap::unary(processFinAcInfo, *this));
}
