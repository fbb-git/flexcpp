#include "rules.ih"

    // On entry iter points at a LOP rule.
void Rules::handleLopRule(vector<Rule>::iterator &iter)
{
    Block block(iter->block());         // save the LOP rule's action block

                                        // change the action into calling
                                        // lop__1, pasing it the SC index of
                                        // the matching 1st SC
    Block sc1Block(block.lineNr(), block.filename());
    sc1Block += "lop1__(" + to_string(iter->scIndex()) + ");\n";
    iter->assignBlock(sc1Block);


}


