#include "rule.ih"

#include <ostream>

ostream &operator<<(ostream &out, Rule const &rule)
{
    out << rule.startState();

    if (size_t accept = rule.accept())
        out << " (" << accept << ')';

    return out;
}
