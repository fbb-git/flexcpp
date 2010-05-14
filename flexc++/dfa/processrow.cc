#include "dfa.ih"

// called from processRule

void DFA::processRow(LARule &laRule, size_t ruleIdx, DFA &dfa,
                     size_t rowIdx, bool parentFinal, int tailSteps)
{
    if (laRule.rule() != ruleIdx)      // stop if laRule is not for this rule
        return;

    DFARow &thisRow = dfa.d_row[rowIdx];
    int final = laRule.final();

        // got post A states for this rule: there are post-A states in this
        // DFA row for the current rule.
    if (thisRow.hasPostAstates(ruleIdx, rowIdx))
    {
        if (laRule.accept() == 0)           // it is the first accept state
        {                                   // set the final accept count if
                                            // this is also a final state
            if (final == LARule::FINAL_NOT_SET) 
                laRule.setFinal(0);
            tailSteps = 1;
        }
        else    // not the first accept state, but there are post-A states
        {       // so there must be an accept count

                // at an undetermined final state:
            if (final == LARule::FINAL_NOT_SET)
                laRule.setFinal(tailSteps - parentFinal);
                    // use the parent's accept count if the parent was also
                    // a final state

            else if (final > tailSteps)
                laRule.setFinal(tailSteps);
                    // use the lowest accept count. Otherwise keep the count

            ++tailSteps;
        }

            // if the row only has post-A states and inc hasn't yet been set
            // then do so now. The accept count is set to the max. accept 
            // count of the post-A states belonging to this rule.
        if (not laRule.inc() && not thisRow.hasPreAstates(ruleIdx, rowIdx))
        {
//            laRule.setAccept(thisRow.maxAccept(ruleIdx));
            laRule.setInc();
   cerr << "  LARule: " << laRule << '\n';
            return;
        }
    }

    cerr << "  LARule: " << laRule << '\n';

        // finally do the transitions: transit to other rows of the DFA and
        // do the same, recursively.
    for_each(thisRow.map().begin(), thisRow.map().end(),
            FnWrap::unary(inspect, rowIdx, ruleIdx, dfa, 
                          laRule.final() != LARule::NOT_FINAL, 
                          tailSteps + 1));
}
