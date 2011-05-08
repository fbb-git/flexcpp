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

/*

Flag Logic (all alternatives are ignored if PROCESSED has been set as well).

    PRE     ACCEPT  POST    d_sawAccept
    -----------------------------------------------------------------------
initialize count for rows representing ACCEPT for the 1st time:

 2   1        1      1          0    	- set COUNT, d_accCount = 0, 
                                                     d_sawAccept = true

 4   1        1      0          0    	- set COUNT, d_accCount = 0, 
                                                     d_sawAccept = true
                                     	
 10  0        1      1          0    	- set COUNT, d_accCount = 0
                                                     d_sawAccept = true

 12  0        1      0          0    	- set COUNT, d_accCount = 0, 
                                                     d_sawAccept = true
                                     	
    -----------------------------------------------------------------------
set INCREMENTING for rows only representing POST states:

 13  0        0      1          1    	- set INCREMENTING

 14  0        0      1          0    	- set INCREMENTING

    -----------------------------------------------------------------------
increment the count for rows representing PRE/ACCEPT and POST states
(this can be handled after the above checks by simply testing for POST)

 1   1        1      1          1    	- set COUNT
                                          d_accCount = previousCount + 1

 5   1        0      1          1    	- set COUNT
                                          d_accCount = previousCount + 1

 9   0        1      1          1    	- set COUNT
                                          d_accCount = previousCount + 1

 6   1        0      1          0    	- set COUNT
                                          d_accCount = previousCount + 1


    -----------------------------------------------------------------------
only PRE/ACCEPT states, and ACCEPT has already been seen: no action

 3   1        1      0          1    	- no action

 11  0        1      0          1    	- no action

    -----------------------------------------------------------------------
only PRE states: no action

 7   1        0      0          1    	- no action

 8   1        0      0          0    	- no action

    -----------------------------------------------------------------------
these states cannot occur with LOP rules as LOP rules either set PRE, ACCEPT
or POST

 15  0        0      0          1    	-       no action (does not occur)

 16  0        0      0          0    	-       no action (does not occur)
    ----------------------------------------------------------------------

*///////////////////////////////////////////////////////////////////////
    
void DFA::computeAccCount(AccCount &accCount, DFA &dfa)
{
    dfa.d_sawACCEPT = false;

                             //   count,
    dfa.inspectAccCount(accCount, 0);



//    int ruleIdx = accCount.rule();
//
//    Rule &rule = (*dfa.d_rules)[ruleIdx];
//
//    if (rule.LAdone())
//        return;

//    vector<bool> visited(dfa.d_states->size());
//    dfa.propagateLAsteps(visited, rule.accept(), 0);

                           // rowIdx, parentFinal,  tailSize          
//    processRule(ruleIdx, dfa, 0,      false,        -1);
//    rule.setLAdone();
}

