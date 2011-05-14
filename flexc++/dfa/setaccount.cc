#include "dfa.ih"

bool DFA::setAccCount(AccCount &thisAccCount, size_t thisRow,
                      AccCount *fmAccCount, size_t fmRow)
{
    AccCount::Type type = thisAccCount.type();      // get the accCount flags

cout << "setAccount: fromRow = " << fmRow << ", this row = " << thisRow << 
", this AccCount = " << thisAccCount  << '\n';

        // only POST states
    if
    (
        not (type & (AccCount::PRE | AccCount::ACCEPT))
        && 
        (type & AccCount::POST) 
    )
    {
        if (type & AccCount::PROCESSED)         // already handled this entry
            return false;

cout << "From " << fmRow << ": incrementing Acc Count for row " << 
thisRow << "from here\n";

        thisAccCount.addFlag(AccCount::PROCESSED | AccCount::INCREMENTING);
    }

        // initialize count for rows representing ACCEPT for the 1st time:
    else if (!d_sawACCEPT && (type & AccCount::ACCEPT))
    {
        if (type & AccCount::PROCESSED)         // already handled this entry
            return false;

        thisAccCount.setAccCount(0);
        thisAccCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
        d_sawACCEPT = true;

cout << "From " << fmRow << ": initialized AccCount for row " << 
thisRow << " to " << thisAccCount << '\n';
    }

    else if (       // Set contains pre/accept  and post states
        (type & AccCount::POST) && (type & (AccCount::PRE | AccCount::ACCEPT))
    )
    {
                                            // compute next Acc. count
        size_t nextCount = fmAccCount->accCount() + 1; 

        if (type && AccCount::COUNT)        // accCount was previously set
        {                                       
                                            // get the actual Acc. count
            size_t thisCount = thisAccCount.accCount(); 

            if (thisRow > fmRow)            // jumping forward
            {
                if (thisCount != nextCount) // counts differ: reset count to 0
                {
                    wmsg << "Rule " << thisAccCount.rule() << 
                            ": conflicting counts for " << fmRow <<
                            " reset to 0" << endl;
    
                    fmAccCount->setAccCount(0);
                }
            }
            else                            // jumping backward
            {                           
                if (nextCount < thisCount)  // next count is smaller: use it
                    fmAccCount->setAccCount(nextCount);
            }

            if (type & AccCount::PROCESSED) // already handled this entry
                return false;
        }
        else if (type & AccCount::PROCESSED)    // already handled this entry
            return false;

        thisAccCount.setAccCount(nextCount);
        thisAccCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);

cout << "From " << fmRow << ": setting count of row " << thisRow << " to " << 
thisAccCount << '\n';

    }
else
{
    if (type & AccCount::PROCESSED)
        return false;
//cout << "NO ACTION BY SETACCCOUNT\n";
}

    return true;
}





