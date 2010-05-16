#include "dfa.ih"

// called from processRule

void DFA::processRow(LARule &laRule, size_t ruleIdx, DFA &dfa,
                     size_t rowIdx, int parentFinal, int tailSteps)
{
    if (laRule.rule() != ruleIdx)      // stop if laRule is not for this rule
        return;

    DFARow &thisRow = dfa.d_row[rowIdx];
    int final = laRule.final();

        // got post A states for this rule: there are post-A states in this
        // DFA row for the current rule.
    if (thisRow.hasPostAstates(ruleIdx, rowIdx))
    {
        if (tailSteps == -1)
            tailSteps = 0;

        if (final != LARule::NOT_FINAL)     // current state is Final state
        {
            cerr << "IN Row " << rowIdx << " has final: " << final << endl;

            if (final == LARule::FINAL_NOT_SET)
                    // keep the parent's final (if set) or use tailsteps
                final = parentFinal >= 0 ? parentFinal : tailSteps;
            else 
                final = min(final, tailSteps);

            cerr << "OUT Row " << rowIdx << " has final: " << final << endl;
            laRule.setFinal(final);
        }

            // if the row only has post-A states and inc hasn't yet been set
            // then do so now. The accept count is set to the max. accept 
            // count of the post-A states belonging to this rule.
        if (not thisRow.hasPreAstates(ruleIdx, rowIdx))
        {
            laRule.setAccept(dfa.maxAccept(rowIdx));
            laRule.setInc();
   cerr << "  row " << rowIdx << ": pure post-A LARule: " << laRule << '\n';
            return;
        }

        laRule.setAccept(tailSteps);
        ++tailSteps;

//    cerr << "  row " << rowIdx << 
//            ": mixed pre/post-A LARule " << laRule << '\n';
    }

        // finally do the transitions: transit to other rows of the DFA and
        // do the same, recursively.
    for_each(thisRow.map().begin(), thisRow.map().end(),
            FnWrap::unary(inspect, rowIdx, ruleIdx, dfa, final, tailSteps));
}

