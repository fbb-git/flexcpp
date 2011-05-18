#include "dfa.ih"

bool DFA::setInitTailCount(TailCount::Type type, TailCount &thisTailCount)
{
    if (type & TailCount::PROCESSED)         // already handled this entry
        return false;

    thisTailCount.setTailCount(0);
    thisTailCount.addFlag(TailCount::PROCESSED | TailCount::COUNT);
    d_sawACCEPT = true;

//cout << "From " << fmRow << ": initialized TailCount for row " << 
//thisRow << " to " << thisTailCount << '\n';

    return true;
}
