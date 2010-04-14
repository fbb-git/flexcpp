#ifndef INCLUDED_RULES_
#define INCLUDED_RULES_

#include <vector>
#include <string>
#include <unordered_map>

#include "../rule/rule.h"

class Rules
{
    typedef std::pair<size_t, size_t> Pair;

    std::vector<Rule> d_rules;
    std::unordered_map<size_t, size_t>  d_reverse;  // from FINAL state to
                                                    // Rule index

    public:
        Rules();

        size_t add(Pair const &pair, size_t accept,
                                     std::string const &action = "");
        Rule const &operator[](size_t idx) const;
};
        
inline Rule const &Rules::operator[](size_t idx) const
{
    return d_rules[idx];
}

#endif
