#include "dfa.ih"

DFA::DFA(Ranges &ranges, Rules &rules, States &states)
:
    d_ranges(&ranges),
    d_rules(&rules),
    d_states(&states)
{}
