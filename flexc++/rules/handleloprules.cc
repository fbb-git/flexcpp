#include "rules.ih"

void Rules::handleLopRules()
{
    setLopBlocks();

    for (
        auto iter = d_rules.begin(), end = d_rules.end(); 
            iter != end; 
                ++iter
    )
    {
        if (iter->isLopRule())
            handleLopRule(iter);
    }
}
