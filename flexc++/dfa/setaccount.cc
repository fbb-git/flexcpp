#include "dfa.ih"

bool DFA::setAccCount(AccCount &accCount, size_t fmRow, size_t thisRow,
                      AccCount *fmAccCount)
{
    AccCount::Type type = accCount.type();      // get the accCount flags

cout << "setAccount: fromRow = " << fmRow << ", this row = " << thisRow << 
", accCount = " << accCount  << '\n';

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

        accCount.addFlag(AccCount::PROCESSED | AccCount::INCREMENTING);
    }

        // initialize count for rows representing ACCEPT for the 1st time:
    else if (!d_sawACCEPT && (type & AccCount::ACCEPT))
    {
        if (type & AccCount::PROCESSED)         // already handled this entry
            return false;

        accCount.setAccCount(0);
        accCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
        d_sawACCEPT = true;

cout << "From " << fmRow << ": initialized AccCount for row " << 
thisRow << " to " << accCount << '\n';
    }
    else if (
        (type & AccCount::POST) && (type & (AccCount::PRE | AccCount::POST))
    )
    {
        size_t fmCount = fmAccCount->accCount() + 1; // inc. the step count

        if (type && AccCount::COUNT)
        {
            if (fmRow < thisRow && accCount.accCount() != fmCount)
            {
                wmsg << "Rule " << accCount.rule() << 
                        ": conflicting counts for " << fmRow <<
                        " reset to 0" << endl;

                fmAccCount->setAccCount(0);
            }
            else if (type & AccCount::PROCESSED)// already handled this entry
                return false;
        }
        else if (type & AccCount::PROCESSED)    // already handled this entry
            return false;

        accCount.setAccCount(fmCount);
        accCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
cout << "From " << fmRow << ": setting count of row " << thisRow << " to " << 
accCount << '\n';

    }
else
{
    if (type & AccCount::PROCESSED)
        return false;
//cout << "NO ACTION BY SETACCCOUNT\n";
}

    return true;
}





