#include "rule.ih"

Rule::Rule(States const &states, Pair fstfin, size_t accept, string action)
:
    d_start(fstfin.first),                  // 1st state of this rule
    d_final(fstfin.second),                 // final state of this rule
    d_action(action),
    d_LAdone(false)
{
    if (accept != 0)                        // this rule uses the LA operator, 
    {                                       // so it has an accept state

        setStates(d_preAstates, states, fstfin.first, accept); 
        setStates(d_postAstates, states, accept, fstfin.second);

        d_postAstates.push_back(fstfin.second); // the final state is also
                                                // of the post-A states

    }
}
