#include "dfa.ih"

bool DFA::setIncTailCount(TailCount::Type type, TailCount &thisTailCount)
{
    if (type & TailCount::PROCESSED)         // already handled this entry
        return false;

//cout << "From " << fmRow << ": incrementing Acc Count for row " << 
//thisRow << "from here\n";

    thisTailCount.addFlag(TailCount::PROCESSED | TailCount::INCREMENTING);

    return true;
}
