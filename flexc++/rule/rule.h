#ifndef INCLUDED_RULE_
#define INCLUDED_RULE_

#include <string>

class Rule
{
    size_t d_start;             // index in States
    size_t d_accept;            // index in States of ACCEPT state (or 0)
    std::string d_action;       // action block

    public:
        Rule(size_t start = 0, size_t accept = 0, std::string action = "");
        size_t startState() const;
        size_t accept() const;
};

inline size_t Rule::startState() const
{
    return d_start;
}

inline size_t Rule::accept() const
{
    return d_accept;
}

std::ostream &operator<<(std::ostream &out, Rule const &rule);

#endif






