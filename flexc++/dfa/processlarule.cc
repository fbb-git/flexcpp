#include "dfa.ih"

// called from processLArules

void DFA::processLArule(LARule const &laRule, DFA &dfa)
{
    int ruleIdx = laRule.rule();

    Rule &rule = (*dfa.d_rules)[ruleIdx];

    if (rule.LAdone())
        return;

    dfa.propagateLAsteps(rule.postAstates(), rule.accept(), 0);

                           // rowIdx, parentFinal, tailSteps          
    processRule(ruleIdx, dfa, 0,       false,        -1);
    rule.setLAdone();
}

