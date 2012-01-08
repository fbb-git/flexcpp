#include "dfa.ih"

bool DFA::setIncTailCount(TailCount::Type type, TailCount &thisTailCount)
{
    if (type & TailCount::PROCESSED)         // already handled this entry
        return false;

//cout << "setIncTailCount: incrementing Acc Count for rule " << 
//thisTailCount.rule() << '\n';

    thisTailCount.addFlag(TailCount::PROCESSED | TailCount::INCREMENTING);

    return true;
}
