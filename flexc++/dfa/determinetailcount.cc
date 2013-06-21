#include "dfa.ih"

void DFA::determineTailCount(TailCount &tailCount, size_t thisRow, 
                            TailCount *fmTailCount, size_t fmRow)
{
    if (d_rule != tailCount.rule())
        return;

//cout << "   initialize tailCount in row " << thisRow << ", coming from " <<
//fmRow << ", previous TailCount (pointer) value: " << fmTailCount << '\n';

if (fmRow == 0)
{
//    cout << "RESETTING d_sawACCEPT\n";
    d_sawACCEPT = false;
}

    if (d_transitSet[fmRow].find(thisRow) == d_transitSet[fmRow].end())
        return;
        // cout << "Already visited transition from " << fmRow << " to " <<
        //         thisRow << " for rule " << d_rule << '\n';

    d_transitSet[fmRow].insert(thisRow);

    if (not setTailCount(tailCount, thisRow, fmTailCount, fmRow))
{
//cout << "No action for this tailCount: done here\n";
        return;
}

//cout << "tailCount in row " << thisRow << " for rule " << d_rule << 
//": " << tailCount.tailCount() << '\n';

    std::unordered_map<size_t, size_t> const &transitMap = 
                                                    d_row[thisRow].map();

    for (auto &rangeToRow: transitMap)
        transitTailCount(rangeToRow, &tailCount, thisRow);
}






