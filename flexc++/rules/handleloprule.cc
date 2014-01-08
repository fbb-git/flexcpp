#include "rules.ih"

    // On entry iter points at a LOP rule.
void Rules::handleLopRule(vector<Rule>::iterator &iter)
{
    Block block(iter->block());         // save the current action block


//    Block sc1Block(block.lineNr(), block.filename());
//    sc1Block += "lop1__(" + to_string(msIndex) + ");\n";
//
//    iter->assignBlock(sc1Block);
}


