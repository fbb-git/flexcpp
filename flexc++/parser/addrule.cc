#include "parser.hh"

    // lineNr is always 1 too large as the parser detects the end of the rule
    // at the line following the rule's definition. Therefore lineNr is
    // here reduced by 1.

    // LOP rules are stored in a vector of LOP rules, containing the
    // information that's available at this point. Once the LOP rule's action
    // is known it can be processed. This happens in assignBlock and in
    // noActions.

void Parser::addRule(Pattern const &pattern, bool reset)
{
    if (not d_scanner.allowNullMatches() && pattern.canBeEmpty(d_states))
    {
        d_nullMatchingRules = true;
        wmsg << "null-matching regular expression" << endl;
    }

    Block block(d_scanner.lineNr() - 1, d_scanner.filename()); // see the
                                                    // comment at the top of 
                                                    // this file

    d_rules.add(d_boln, pattern, block, pattern.type());

    if (reset)
        d_rules.resetStartConditions();
}


