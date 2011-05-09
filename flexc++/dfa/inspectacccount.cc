#include "dfa.ih"

bool DFA::inspectAccCount(AccCount &accCount, size_t count)
{
    AccCount::Type type = accCount.type();

    // initialize count for rows representing ACCEPT for the 1st time:

    if (!d_sawACCEPT && (type & AccCount::ACCEPT))
    {
        if (type & AccCount::PROCESSED)         // already handled this entry
            return false;

        accCount.setAccCount(0);
        accCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
        d_sawACCEPT = true;

cout << "Initialized AccCount\n";
        
    }
    else if (not (type & (AccCount::PRE | AccCount::ACCEPT)))
    {
        if (type & AccCount::PROCESSED)         // already handled this entry
            return false;

cout << "Incrementing Acc Count from here\n";

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
            return false;

cout << "Incrementing previous count to " << count + 1 << '\n';

        accCount.setAccCount(count + 1);
        accCount.addFlag(AccCount::PROCESSED | AccCount::COUNT);
    }
else
cout << "No action by inspectAccCount\n";

    return true;
}





