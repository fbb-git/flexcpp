#include "dfa.ih"

void DFA::determineTailCount(TailCount &tailCount, size_t thisRow, 
                            TailCount *fmTailCount, size_t fmRow, DFA &dfa)
{
    if (dfa.d_rule != tailCount.rule())
        return;

//cout << "   initialize tailCount in row " << thisRow << ", coming from " <<
//fmRow << ", previous TailCount value: " << fmCount << '\n';

    if (not dfa.setTailCount(tailCount, thisRow, fmTailCount, fmRow))
{
//cout << "No action for this tailCount: done here\n";
        return;
}

//cout << "tailCount in row " << thisRow << " for rule " << dfa.d_rule << 
//": " << tailCount.tailCount() << '\n';

    std::unordered_map<size_t, size_t> const &transitMap = 
                                                    dfa.d_row[thisRow].map();

    for_each(transitMap.begin(), transitMap.end(), 
        FnWrap::unary(transitTailCount, &tailCount, thisRow, dfa));
}

