#include "rule.ih"

Rule::Rule(size_t start, size_t accept, string action)
:
    d_start(start),
    d_accept(accept),
    d_action(action)
{}
