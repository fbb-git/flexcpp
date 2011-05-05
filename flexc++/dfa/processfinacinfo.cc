#include "dfa.ih"

// called from processFinAc

void DFA::processFinAcInfo(FinAcInfo const &finAcInfo, DFA &dfa)
{
    int ruleIdx = finAcInfo.rule();

    Rule &rule = (*dfa.d_rules)[ruleIdx];

    if (rule.LAdone())
        return;

    vector<bool> visited(dfa.d_states->size());
    dfa.propagateLAsteps(visited, rule.accept(), 0);

                           // rowIdx, parentFinal,  tailSize          
    processRule(ruleIdx, dfa, 0,      false,        -1);
    rule.setLAdone();
}

