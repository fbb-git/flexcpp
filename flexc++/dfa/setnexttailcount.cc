#include "dfa.ih"

bool DFA::setNextTailCount(TailCount::Type type, 
                            TailCount &thisTailCount, size_t thisRow,
                            TailCount &fmTailCount, size_t fmRow)
{
//cout << "Fm " << fmRow << " to " << thisRow << ": " << thisTailCount << endl;

                                        // compute next Acc. count
    size_t nextCount = fmTailCount.tailCount() + 1; 

    if (not (type & TailCount::COUNT))   // no count was set as yet
    {
        thisTailCount.setTailCount(nextCount);
        thisTailCount.addFlag(TailCount::PROCESSED | TailCount::COUNT);
    }
    else
    {
        size_t thisCount = thisTailCount.tailCount(); 

        if (fmRow < thisRow)            // jumping forward
        {
                                        // counts differ: reset count to 0
            if (thisCount != 0 && thisCount != nextCount) 
            {
                wmsg << "Rule " << thisTailCount.rule() << 
                        ": conflicting counts for " << thisRow << " (" << 
                        thisCount << ", " << nextCount << ") reset to 0" << 
                        endl;

                thisTailCount.setTailCount(0);
            }
        }                               // jumping backward:
    }

//cout << "Fm " << fmRow << " to " << thisRow << ": count = " <<
//thisTailCount.tailCount() << '\n'; 

    return not (type & TailCount::PROCESSED);
}
