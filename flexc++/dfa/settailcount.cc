#include "dfa.ih"

bool DFA::setTailCount(TailCount &thisTailCount, size_t thisRow,
                      TailCount *fmTailCount, size_t fmRow)
{
    TailCount::Type type = thisTailCount.type();      // get the tailCount flags

//cout << "setAccount: fromRow = " << fmRow << ", this row = " << thisRow << 
//", this TailCount = " << thisTailCount  << '\n';
        
    if (not (type & (TailCount::PRE | TailCount::ACCEPT)))    // only POST st.
    {
        if (not setIncTailCount(type, thisTailCount))
            return false;
    }
    else
        // beyond here PRE and/or ACCEPT are in the set
        if (!d_sawACCEPT && (type & TailCount::ACCEPT))     // 1st time ACCEPT
    {
        if (not setInitTailCount(type, thisTailCount))
            return false;
    }
    else if (type & TailCount::POST)  // Set with pre/accept  and post states
    {
        if (not setNextTailCount(type, thisTailCount, thisRow, 
                                      *fmTailCount, fmRow))
            return false;
    }
    else if (type & TailCount::PROCESSED)
        return false;

    return true;
}





