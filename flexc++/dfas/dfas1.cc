#include "dfas.hh"

DFAs::DFAs(Rules &rules, States &states, Ranges &ranges)
:
    d_rules(rules),
    d_states(states),
    d_ranges(ranges)
{}
