#include "dfas.ih"

DFAs::DFAs(Rules &rules, States const &states, Ranges &ranges)
:
    d_rules(rules),
    d_states(states),
    d_ranges(ranges)
{}
