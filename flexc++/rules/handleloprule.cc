#include "rules.ih"

    // On entry iter points at a LOP rule.
void Rules::handleLopRule(Rule &rule)
{
    if (not rule.isLopRule())
        return;
//
//cerr << "\nLOP RULE\n\n";
//    Block action(rule.block());        // save the LOP rule's action block
//
//    Pattern const &pattern = rule.pattern();
//
//cerr << 
//"LOP rule pair: " << pattern.pair().first << ", " << pattern.pair().second <<
//'\n' <<
//"LHS rule pair: " << pattern.lhs().pair().first << ", " << pattern.lhs().pair().second <<
//'\n' << 
//"RHS rule pair: " << pattern.rhsPair().first << ", " << pattern.rhsPair().second <<
//'\n'; 
//
//    size_t scIndex = pattern.scIndex();
//
//                                        // change the LOP rule's action into 
//                                        // calling lop__1, pasing it the SC 
//                                        // index of its 1st SC
//    Block workBlock(action.lineNr(), action.filename());
//    workBlock += "lop1__(" + to_string(scIndex) + ");\n";
//    rule.assignBlock(workBlock);
//
//                                        // activate the LOP rule's 1st SCs:
//    d_startConditions.activate(scIndex);
//
//    workBlock.clear();                  // lop2__() switches to the 2nd SC
//    workBlock += "lop2__();\n";         // and pushes the initial part of the 
//                                        // matched text on to the input stream
//
//cerr << "RHS pair of the LOP rule: " << pattern.rhsPair().first <<
//", " << pattern.rhsPair().second << '\n';
//
//cerr << "\nLHS rule pair: " << pattern.lhs().pair().first << ", " <<
//pattern.lhs().pair().second << '\n' << '\n';
//
//cerr << "=================\n";
//                                        // add this rule to the 1st SC
////    add(false, Pattern(pattern.rhsPair()), workBlock);
//
//cerr << "=================\n";
//cerr << "\nLHS rule pair: " << pattern.lhs().pair().first << ", " <<
//pattern.lhs().pair().second << '\n' << '\n';
//
//
//cerr << "The catch-all rule is rule idx " << d_catchAllIndex  << '\n';
//
//    d_startConditions.add(d_catchAllIndex);
////    addCatchAll();
//
//
//                                        // activate the LOP rule's 2nd SCs:
//    d_startConditions.activate(scIndex + 1);
//
//    workBlock.clear();                  // lop4__ returns to the previous SC
//    workBlock += "lop4__();\n" + action.str();  // and puses the LOP's tail
//                                                // on to the input stream
//
//cerr << "LHS pair of the LOP rule: " << pattern.lhs().pair().first <<
//", " << pattern.lhs().pair().second << '\n';
//
//
//                                        // add this rule to the 2nd SC
//    add(false, pattern.lhs(), workBlock);   
}


