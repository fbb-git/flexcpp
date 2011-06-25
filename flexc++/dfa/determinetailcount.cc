#include "dfa.ih"

void DFA::determineTailCount(TailCount &tailCount, size_t thisRow, 
                            TailCount *fmTailCount, size_t fmRow)
{
    if (d_rule != tailCount.rule())
        return;

//cout << "   initialize tailCount in row " << thisRow << ", coming from " <<
//fmRow << ", previous TailCount value: " << fmCount << '\n';

    if (not setTailCount(tailCount, thisRow, fmTailCount, fmRow))
{
//cout << "No action for this tailCount: done here\n";
        return;
}

//cout << "tailCount in row " << thisRow << " for rule " << d_rule << 
//": " << tailCount.tailCount() << '\n';

    std::unordered_map<size_t, size_t> const &transitMap = 
                                                    d_row[thisRow].map();

    for_each(
        transitMap.begin(), transitMap.end(), 
        [&, this](DFARow::MapValue const &rangeToRow)
        {
            this->transitTailCount(rangeToRow, &tailCount, thisRow);
        }
    );
}




