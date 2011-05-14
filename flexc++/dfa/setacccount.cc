#include "dfa.ih"

bool DFA::setAccCount(AccCount &thisAccCount, size_t thisRow,
                      AccCount *fmAccCount, size_t fmRow)
{
    AccCount::Type type = thisAccCount.type();      // get the accCount flags

//cout << "setAccount: fromRow = " << fmRow << ", this row = " << thisRow << 
//", this AccCount = " << thisAccCount  << '\n';
        
    if (not (type & (AccCount::PRE | AccCount::ACCEPT)))    // only POST st.
    {
        if (not setIncAccCount(type, thisAccCount))
            return false;
    }
    else
        // beyond here PRE and/or ACCEPT are in the set
        if (!d_sawACCEPT && (type & AccCount::ACCEPT))     // 1st time ACCEPT
    {
        if (not setInitAccCount(type, thisAccCount))
            return false;
    }
    else if (type & AccCount::POST)  // Set with pre/accept  and post states
    {
        if (not setNextAccCount(type, thisAccCount, thisRow, 
                                      *fmAccCount, fmRow))
            return false;
    }
    else if (type & AccCount::PROCESSED)
        return false;

    return true;
}





