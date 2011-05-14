#include "dfa.ih"

bool DFA::setInitAccCount(AccCount::Type type, AccCount &thisAccCount)
{
    if (type & AccCount::PROCESSED)         // already handled this entry
        return false;

    thisAccCount.setAccCount(0);
    thisAccCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
    d_sawACCEPT = true;

//cout << "From " << fmRow << ": initialized AccCount for row " << 
//thisRow << " to " << thisAccCount << '\n';

    return true;
}
