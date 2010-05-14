#include "dfa.ih"

// This function visits all rules at dfa row 0
// 
// It calls processLArule that picks up the rule nr from the LARule object
// calling processRule to process the DFA for the current rule (for each rule
// using the LA operator this happends only once).
// 
// processRule checks whether the requested rule is available at the current
// DFA row and if so it calls processRule to set/inspect the LARule for the
// given rule at the given DFA row.
//
// processRule calls processRow to do the actual work, calling inspect for
// each transition.
//
// inspect calls

void DFA::processLArules()
{
    for_each(d_row[0].laRules().begin(), d_row[0].laRules().end(),
             FnWrap::unary(processLArule, *this));
}
