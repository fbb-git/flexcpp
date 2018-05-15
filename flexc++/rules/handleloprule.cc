#include "rules.ih"

    // returns the index of the SC to receive the catch-all rule
size_t Rules::handleLopRule(size_t idx)
{
    d_lopToRule[d_rules.size()] = idx;  // set the implied viable relation

    Rule *rule = &d_rules[idx];

    Block action(rule->block());        // save the LOP rule's action block

    Pattern const *pattern = &rule->pattern();

    size_t scIndex = pattern->scIndex();

                                        // change the LOP rule's action into 
                                        // calling lop_1, pasing it the SC 
                                        // index of its 1st SC
    Block workBlock(action.lineNr(), action.filename());
    workBlock += "lop1_(" + to_string(scIndex) + ");" ;
    rule->assignBlock(workBlock);

            // lop2_() is called when the LOP's tail was matched. 
            // It then switches to the 2nd SC and pushes the initial part of
            // the matched text on to the input stream
    workBlock.clear();
    workBlock += "lop2_();";

                                        // activate the LOP rule's 1st SCs:
    d_startConditions.activate(scIndex);
                                        // and add this rule to that SC
    add(false, Pattern(pattern->rhsPair()), workBlock, RuleType::LOP_2);


    pattern = &d_rules[idx].pattern();  // reassign the pointer to the current
                                        // rule, as the vector may have
                                        // resized

    // lop3_() is called via the Scanner's needCatchAll() member in
    // scanner.h, called by Parser::lookahead.
    
                                        // activate the LOP rule's 2nd SCs:
    d_startConditions.activate(scIndex + 1);

        // Code executed after the LOP's head has been matched
    workBlock.clear();                  // lop4_ returns to the previous SC
    workBlock += "lop4_();";           // and pushes the LOP's tail on to the
    workBlock += "\n";                  // input stream.
    workBlock.addContents(action);

    workBlock.setLineNr(workBlock.lineNr());    // compensate for the
                                                // lop4_() line.

                                        // add this rule to the 2nd SC
    add(false, pattern->lhs(), workBlock, RuleType::LOP_4);   

    return scIndex;
}







