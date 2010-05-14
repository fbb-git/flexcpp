#include "dfa.ih"

void DFA::processLArule(LARule const &laRule, DFA &dfa)
{
    int ruleIdx = laRule.rule();

    Rule &rule = (*dfa.d_rules)[ruleIdx];

    if (rule.LAdone())
        return;
                           // rowIdx, parentFinal, acceptCount          
    processRule(ruleIdx, dfa, 0,       true,        0);
    rule.setLAdone();
}

