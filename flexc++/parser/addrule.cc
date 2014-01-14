#include "parser.ih"

    // lineNr is always 1 too large as the parser detects the end of the rule
    // at the line following the rule's definition. Therefore lineNr is
    // here reduced by 1.

    // LOP rules are stored in a vector of LOP rules, containing the
    // information that's available at this point. Once the LOP rule's action
    // is known it can be processed. This happens in assignBlock and in
    // noActions.

void Parser::addRule(Pattern const &pattern, bool reset)
{
    Block block(d_scanner.lineNr(), d_scanner.filename());


    d_rules.add(d_boln, pattern, block, 
                    pattern.isLopPattern() ? 
                        RuleType::LOP_1
                    :
                        RuleType::NORMAL
    );

    if (reset)
        d_rules.resetStartConditions();
}


