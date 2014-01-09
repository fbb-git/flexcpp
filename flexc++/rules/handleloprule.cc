#include "rules.ih"

void Rules::handleLopRule(size_t idx)
{
    Rule *rule = &d_rules[idx];

    Block action(rule->block());        // save the LOP rule's action block

    Pattern const *pattern = &rule->pattern();

    size_t scIndex = pattern->scIndex();

                                        // change the LOP rule's action into 
                                        // calling lop__1, pasing it the SC 
                                        // index of its 1st SC
    Block workBlock(action.lineNr(), action.filename());
    workBlock += "lop1__(" + to_string(scIndex) + ");\n";
    rule->assignBlock(workBlock);

                                        // activate the LOP rule's 1st SCs:
    d_startConditions.activate(scIndex);

    workBlock.clear();                  // lop2__() switches to the 2nd SC
    workBlock += "lop2__();\n";         // and pushes the initial part of the 
                                        // matched text on to the input stream


                                        // add this rule to the 1st SC
    add(false, Pattern(pattern->rhsPair()), workBlock);

    pattern = &d_rules[idx].pattern();  // reset the pointer, as the vector 
                                        // may have resized

                                        // activate the LOP rule's 2nd SCs:
    d_startConditions.activate(scIndex + 1);

    workBlock.clear();                  // lop4__ returns to the previous SC
    workBlock += "lop4__();\n" + action.str();  // and puses the LOP's tail
                                                // on to the input stream

                                        // add this rule to the 2nd SC
    add(false, pattern->lhs(), workBlock);   
}







