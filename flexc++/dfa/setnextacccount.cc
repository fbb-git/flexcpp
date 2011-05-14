#include "dfa.ih"

bool DFA::setNextAccCount(AccCount::Type type, 
                            AccCount &thisAccCount, size_t thisRow,
                            AccCount &fmAccCount, size_t fmRow)
{
//cout << "Fm " << fmRow << " to " << thisRow << ": " << thisAccCount << endl;

                                        // compute next Acc. count
    size_t nextCount = fmAccCount.accCount() + 1; 

    if (not (type & AccCount::COUNT))   // no count was set as yet
    {
        thisAccCount.setAccCount(nextCount);
        thisAccCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
    }
    else
    {
        size_t thisCount = thisAccCount.accCount(); 

        if (fmRow < thisRow)            // jumping forward
        {
                                        // counts differ: reset count to 0
            if (thisCount != 0 && thisCount != nextCount) 
            {
                wmsg << "Rule " << thisAccCount.rule() << 
                        ": conflicting counts for " << thisRow << " (" << 
                        thisCount << ", " << nextCount << ") reset to 0" << 
                        endl;

                thisAccCount.setAccCount(0);
            }
        }                               // jumping backward:
    }

//cout << "Fm " << fmRow << " to " << thisRow << ": count = " <<
//thisAccCount.accCount() << '\n'; 

    return not (type & AccCount::PROCESSED);
}
