#include "dfa.ih"

// See all possibilities in the tech manual (The logic used in
// 'setTailCount').
// That table shows all possible flag/sawAccept combinations and describes the
// action to perform on each combination

bool DFA::setTailCount(TailCount &thisTailCount, size_t thisRow,
                      TailCount *fmTailCount, size_t fmRow)
{
    TailCount::Type type = thisTailCount.type();  // get the tailCount flags

//cout << "setTailCount: TailCount = " << thisTailCount << '\n';
    
//cout << "setTailCount: fromRow = " << fmRow << ", this row = " << thisRow <<
//", this TailCount = " << thisTailCount  << '\n';

    if (type & TailCount::PROCESSED)            // moved to here rather than
        return false;                           // at the end since 1.06.00
 
    // States: 1 9
    if (not (type & (TailCount::PRE | TailCount::ACCEPT)))    // only POST st.
    {
        if (not setIncTailCount(type, thisTailCount))
            return false;
    }
    else
        // beyond here PRE and/or ACCEPT are in the set
        if (!d_sawACCEPT && (type & TailCount::ACCEPT))     // 1st time ACCEPT
    {
        // States:     2 3     6 7                             
        if (not setInitTailCount(type, thisTailCount))
            return false;
    }
    else if (type & TailCount::POST)  // Set with pre/accept  and post states
    {
        // States:           5            11    13    15       
        if (not setNextTailCount(type, thisTailCount, thisRow, 
                                      *fmTailCount, fmRow))
            return false;
    }
//    else if (type & TailCount::PROCESSED)
//        return false;

    // States: 0       4       8   10    12    14
    thisTailCount.addFlag(TailCount::PROCESSED);
    return true;
}





