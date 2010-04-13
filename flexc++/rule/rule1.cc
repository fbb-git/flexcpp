#include "rule.ih"

Rule::Rule(size_t start, size_t accept, bool inheriting, string action)
:
    d_start(start),
    d_accept(accept),
    d_inheriting(inheriting),
    d_action(action)
{}
