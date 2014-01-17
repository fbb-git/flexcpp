#include "generator.ih"

void Generator::actions(ostream &out) const
{
    key(out);


    // First handle the rules which must be handled as-is:

    static RuleType blockTypes[] = {
                RuleType::NORMAL,
                RuleType::LOP_FIXED,
                RuleType::LOP_1,
                RuleType::LOP_4
            };

    bool lineDirectives = d_lineDirectives;

    for (RuleType type: blockTypes)
    {
        size_t idx = 0;
        for (auto &rule: ranger(d_rules.ruleBegin(), d_rules.ruleEnd()))
        {
            d_lineDirectives = 
                    type == RuleType::LOP_1 ? 
                        false 
                    :
                        lineDirectives; 

            if (rule.type() == type)
                ruleAction(rule.block(), out, idx);
            ++idx;
        }
    }    

    d_lineDirectives = false;

    // then handle the rules for which flexc++ may fall through:

    static RuleType fallThroughTypes[] = {
                RuleType::LOP_2,
                RuleType::LOP_3,
            };

    auto first = d_rules.ruleBegin();
    auto end = d_rules.ruleEnd();

    for (RuleType type: fallThroughTypes)
    {
        if (type == RuleType::LOP_4)
            d_lineDirectives = lineDirectives;

        auto rule = find_if(first, end, 
            [&](Rule const &rule)
            {
                return rule.type() == type;
            }
        );
        if (rule == end)
            continue;

        size_t caseLabel = rule - first;  // eventual case label
        size_t idx = caseLabel + 1;     // iterates in parallel with 'next':

        for (auto next = rule + 1; next != end; ++next, ++idx)
        {
            if (next->type() == type)
                out << "        case " << idx << ":\n";
        }

        ruleAction(rule->block(), out, caseLabel);
    }    
}




