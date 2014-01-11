#include "rules.ih"

    // returns the index of the SC to receive the catch-all rule
size_t Rules::handleLopRule(size_t idx)
{
    d_impliedViable[d_rules.size()] = idx;  // set the implied viable relation

    Rule *rule = &d_rules[idx];

    Block action(rule->block());        // save the LOP rule's action block

    Pattern const *pattern = &rule->pattern();

    size_t scIndex = pattern->scIndex();

                                        // change the LOP rule's action into 
                                        // calling lop__1, pasing it the SC 
                                        // index of its 1st SC
    Block workBlock(action.lineNr(), action.filename());
    workBlock += "FULL match lop1__(" + to_string(scIndex) + ");\n";
    rule->assignBlock(workBlock);

                                        // lop2__() is called when the tail
                                        // matches. It then switches to the
    workBlock.clear();                  // 2nd SC
    workBlock += "TAIL match lop2__();\n";// and pushes the initial part of the 
                                        // matched text on to the input stream


                                        // activate the LOP rule's 1st SCs:
    d_startConditions.activate(scIndex);
                                        // and add this rule to that SC
    add(false, Pattern(pattern->rhsPair()), workBlock, RuleType::LOP_2);


    pattern = &d_rules[idx].pattern();  // reassign the pointer to the current
                                        // rule, as the vector may have
                                        // resized


                                        // activate the LOP rule's 2nd SCs:
    d_startConditions.activate(scIndex + 1);

    workBlock.clear();                  // lop4__ returns to the previous SC
    workBlock += "HEAD match lop4__();\n" + action.str();  // and puses the LOP's tail
                                                // on to the input stream

                                        // add this rule to the 2nd SC
    add(false, pattern->lhs(), workBlock, RuleType::LOP_4);   

    return scIndex;
}







