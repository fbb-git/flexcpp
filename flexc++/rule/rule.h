#ifndef INCLUDED_RULE_
#define INCLUDED_RULE_

#include <string>

class Rule
{
    size_t d_start;             // index in States
    size_t d_accept;            // index in States of ACCEPT state (or 0)
    bool d_inheriting;          // set to true if d_accept is an inheriting 
                                // ACCEPT state.
    std::string d_action;       // action block

    public:
        Rule(size_t start = 0, size_t accept = 0, bool inheriting = false, 
             std::string action = "");
};

#endif
