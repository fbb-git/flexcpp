#include "startconditions.hh"

void StartConditions::remove(size_t ruleIndex)
{
    for (auto &element: d_sc) 
    {
        std::vector<size_t> &rules = element.second.d_rules;
        auto iter = ::find(rules.begin(), rules.end(), ruleIndex);
        if (iter != rules.end())
            rules.erase(iter);
    }
}


