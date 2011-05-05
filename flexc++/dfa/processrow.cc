#include "dfa.ih"

// called from processRule

// #include <stdexcept>     not needed, see the next comment 

void DFA::processRow(FinAcInfo &finAcInfo, size_t ruleIdx, DFA &dfa,
                     size_t rowIdx, int parentFinal, int tailSize)
{
// This cannot happen, see the test for ruleIdx in processRule:
//
//    if (finAcInfo.rule() != ruleIdx)  // stop if finAcInfo is not for this
//                                      //rule
//        throw logic_error("DFA::processRow: rule mismatch");


    DFARow &thisRow = dfa.d_row[rowIdx];
    bool final = finAcInfo.final();

        // got post A states for this rule: there are post-A states in this
        // DFA row for the current rule.
    if (thisRow.hasPostAstates(ruleIdx, rowIdx))
    {
        if (tailSize == -1)
            tailSize = 0;

//        if (final != FinAcInfo::NOT_FINAL)     // current state is Final
        if (final)

        {
// cout << "IN Row " << rowIdx << " has final: " << final << endl;

//            if (final == FinAcInfo::FINAL)
                    // keep the parent's final (if set) or use tailsteps
                final = parentFinal >= 0 ? parentFinal : tailSize;
//            else 
//                final = min(final, tailSize);

// cout << "OUT Row " << rowIdx << " has final: " << final << endl;

            finAcInfo.setFinal(final);
        }

            // if the row only has post-A states and inc hasn't yet been set
            // then do so now. The accept count is set to the max. accept 
            // count of the post-A states belonging to this rule.
        if (not thisRow.hasPreAstates(ruleIdx, rowIdx))
        {
            finAcInfo.setAccept(dfa.maxAccept(rowIdx));
            finAcInfo.setInc();
// cerr << "  row " << rowIdx << ": pure post-A FinAcInfo: " << finAcInfo <<
// '\n'; 

    // this is not a FIXED final value. Is it necessary to set final's value?
    // couldn't the code generation detect that this is a final state and an
    // incrementing Accept state and thus determine that |TAIL| will be the
    // current accept count if this is the final DFA state for this rule?
    // In that case final != NOT_FINAL is enough information for the code
    // generator to decide what to do
    //
    // At this point we're always in an A++ state, so the |TAIL| length is
    // variable anyway. So it looks as though we merely need to know that this
    // is a possible Final state, in which case the current A value is the
    // Final's |TAIL|
//            if (final != FinAcInfo::NOT_FINAL)
//                finAcInfo.setFinal(finAcInfo.accept());
            return;
        }

        finAcInfo.setAccept(tailSize);
        ++tailSize;
//    cerr << "  row " << rowIdx << 
//            ": mixed pre/post-A FinAcInfo " << finAcInfo << '\n';
    }

        // finally do the transitions: transit to other rows of the DFA and
        // do the same, recursively.
    for_each(thisRow.map().begin(), thisRow.map().end(),
            FnWrap::unary(inspect, rowIdx, ruleIdx, dfa, final, tailSize));
}
