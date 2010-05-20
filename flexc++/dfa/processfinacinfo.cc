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

                           // rowIdx, parentFinal,          tailSteps          
    processRule(ruleIdx, dfa, 0,      FinAcInfo::NOT_FINAL,    -1);
    rule.setLAdone();
}

