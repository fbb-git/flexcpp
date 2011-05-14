#include "dfa.ih"

bool DFA::setIncAccCount(AccCount::Type type, AccCount &thisAccCount)
{
    if (type & AccCount::PROCESSED)         // already handled this entry
        return false;

//cout << "From " << fmRow << ": incrementing Acc Count for row " << 
//thisRow << "from here\n";

    thisAccCount.addFlag(AccCount::PROCESSED | AccCount::INCREMENTING);

    return true;
}
