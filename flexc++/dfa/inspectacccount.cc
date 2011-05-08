#include "dfa.ih"

void DFA::inspectAccCount(AccCount &accCount, size_t count)
{
    AccCount::Type type = accCount.type();

    // initialize count for rows representing ACCEPT for the 1st time:

    if (!d_sawACCEPT && (type & AccCount::ACCEPT))
    {
        if (type & AccCount::PROCESSED)         // already handled this entry
            return;

        accCount.setAccCount(count);
        accCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
        d_sawACCEPT = true;
        ++count;                                // prepare for the next count
    }
    else if (not (type & (AccCount::PRE | AccCount::ACCEPT)))
    {
        if (type & AccCount::PROCESSED)         // already handled this entry
            return;

        accCount.addFlag(AccCount::PROCESSED | AccCount::INCREMENTING);
    }
    else if (type & AccCount::POST)
    {
        if (type && AccCount::COUNT)
        {
            if (accCount.accCount() != count)   // conflicting count
            {
                wmsg << "Conflicting counts reset to 0" << endl;
                count = 0;
            }
        }
        else if (type & AccCount::PROCESSED)    // already handled this entry
            return;

        accCount.setAccCount(count);
        accCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
        ++count;
    }


}





