#include "dfa.ih"

// called from computeTailCounts

// Using the TailCount element 
// the receiving the rule nr from the TailCount object
// calling processRule to process the DFA for the current rule (for each rule
// using the LA operator this happends only once).
// 
// processRule checks whether the requested rule is available at the current
// DFA row and if so it calls processRule to set/inspect the TailCount for the
// given rule at the given DFA row.
//
// processRule calls processRow to do the actual work, calling inspect for
// each transition.

//FBB
    
//void DFA::visitTailCount(TailCount &tailCount)
//{
////    d_sawACCEPT = false;
//    d_rule = tailCount.rule();
//
//                            // (re)initialize for this rule
//    d_transitSet = vector<Size_tSet>(d_row.size()); 
//
//                            // this/previous row, ptr to previous TailCount 
//    determineTailCount(tailCount, 0, 0, 0);
//}
