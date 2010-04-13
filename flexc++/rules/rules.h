#ifndef INCLUDED_RULES_
#define INCLUDED_RULES_

#include <vector>
#include <string>

#include "../rule/rule.h"

class Rules
{
    std::vector<Rule> d_rules;

    public:
        Rules();

        size_t add(size_t beginState, size_t accept, bool inheriting, 
                                        std::string const &action = "");
};
        

#endif
