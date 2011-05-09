#include "dfa.ih"

// called from computeAccCounts

// Using the AccCount element 
// the receiving the rule nr from the AccCount object
// calling processRule to process the DFA for the current rule (for each rule
// using the LA operator this happends only once).
// 
// processRule checks whether the requested rule is available at the current
// DFA row and if so it calls processRule to set/inspect the AccCount for the
// given rule at the given DFA row.
//
// processRule calls processRow to do the actual work, calling inspect for
// each transition.

    
void DFA::visitAccCount(AccCount &accCount, DFA &dfa)
{
    dfa.d_sawACCEPT = false;
    dfa.d_rule = accCount.rule();

cout << "visitAccCount (initial) for rule " << dfa.d_rule << '\n';    

                            // this row, previous row, previous count
    determineAccCount(accCount, 0, 0, 0, dfa);
}

