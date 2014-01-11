#include "generator.ih"

void Generator::actions(ostream &out) const
{
    key(out);


    // First handle the non-LOP rule actions:
    // this allows falling throug if rules are using OR actions

    static RuleType blockTypes[] = {
                RuleType::NORMAL,
                RuleType::LOP_1
            };

// TEMPORARILY mutable!!
d_lineDirectives = false;

        size_t idx = 0;
        for (auto &rule: ranger(d_rules.ruleBegin(), d_rules.ruleEnd()))
        {
                ruleAction(rule.block(), out, idx);
            ++idx;
        }
//
//    for (RuleType type: blockTypes)
//    {
//        size_t idx = 0;
//        for (auto &rule: ranger(d_rules.ruleBegin(), d_rules.ruleEnd()))
//        {
//            if (rule.type() == type)
//                ruleAction(rule.block(), out, idx);
//            ++idx;
//        }
//    }    
//
//    static RuleType fallThroughTypes[] = {
//                RuleType::LOP_2,
//                RuleType::LOP_3,
//                RuleType::LOP_4,
//            };
//
//    for (RuleType type: fallThroughTypes)
//    {
//        auto end = d_rules.ruleEnd();
//        auto rule = find_if(d_rules.ruleBegin(), end, 
//            [&](Rule const &rule)
//            {
//                return rule.type() == type;
//            }
//        );
//
//        if (rule == end)
//            continue;
//
//        size_t caseLabel = end - rule;  // eventual case label
//        size_t idx = caseLabel + 1;     // iterates in parallel with 'next':
//
//        for (auto next = rule + 1; next != end; ++next, ++idx)
//        {
//            if (next->type() == type)
//                out << "        case " << idx << ":\n";
//        }
//
//        ruleAction(rule->block(), out, caseLabel);
//    }    
}




