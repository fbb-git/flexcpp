#include "dfa.ih"

bool DFA::setAccCount(AccCount &accCount, size_t fmRow, size_t thisRow,
                          size_t fmCount)
{
    AccCount::Type type = accCount.type();      // get the accCount flags

//cout << "AccCount row: " << thisRow << ": " << accCount  << '\n';

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

//cout << "Incrementing Acc Count from here\n";

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

//cout << "Initialized AccCount\n";
    }
    else if (
        (type & AccCount::POST) && (type & (AccCount::PRE | AccCount::POST))
    )
    {
        ++fmCount;                        // increment the step count
        if (type && AccCount::COUNT)
        {
            if (fmRow < thisRow && accCount.accCount() != fmCount)
            {
                wmsg << "Conflicting counts reset to 0" << endl;
                fmCount = 0;
            }
            else if (type & AccCount::PROCESSED)// already handled this entry
            return false;
        }
        else if (type & AccCount::PROCESSED)    // already handled this entry
            return false;

//cout << "Incrementing previous count to " << fmCount << '\n';

        accCount.setAccCount(fmCount);
        accCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
    }
else
{
    if (type & AccCount::PROCESSED)
        return false;
//cout << "NO ACTION BY SETACCCOUNT\n";
}

    return true;
}





