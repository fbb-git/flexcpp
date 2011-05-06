#include "dfa.ih"

// This function visits all rules at dfa row 0
// 
// It calls processFinAc that picks up the rule nr from the FinAc object
// calling processRule to process the DFA for the current rule (for each rule
// using the LA operator this happends only once).
// 
// processRule checks whether the requested rule is available at the current
// DFA row and if so it calls processRule to set/inspect the FinAc for the
// given rule at the given DFA row.
//
// processRule calls processRow to do the actual work, calling inspect for
// each transition.

void DFA::processFinAc()
{
    for_each(d_row[0].finAcs().begin(), d_row[0].finAcs().end(),
             FnWrap::unary(processFinAcElement, *this));
}
