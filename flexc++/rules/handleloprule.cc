#include "rules.ih"

void Rules::handleLopRule(vector<Rule>::iterator &iter)
{
        // make sure LOP rules have their own action blocks:
    auto &blockIter = iter;

    while (blockIter->block().orAction())
        ++blockIter;

    if (blockIter != iter)
        iter->assignBlock(blockIter->block());

//    cerr << "There are " << d_startConditions.size() << " SCs\n";
        // 
}

