#include "rules.ih"

void Rules::handleLopRule(vector<Rule>::iterator &iter)
{
        // make sure LOP rules have their own action blocks:
    auto &blockIter = iter;

    while (blockIter->block().orAction())
        ++blockIter;

    if (blockIter != iter)
        iter->assignBlock(blockIter->block());

    size_t msIndex = d_startConditions.size();

        // Add the new start conditions for this LOP
    string startCond1 = "_" + to_string(msIndex) + "_1__";
//    addStartCondition(startCond1, true);
//    
//    string startCond2 = "_" + to_string(msIndex + 1) + "_2__";
//    addStartCondition(startCond2, true);
// 
//    Block block(iter->block());         // save the current action block
//
//    Block sc1Block(block.lineNr(), block.filename());
//    sc1Block += "lop1__(" + to_string(msIndex) + ");\n";
//
//    iter->assignBlock(sc1Block);
}


