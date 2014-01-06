#include "pattern.ih"

Pattern::Pattern(Pattern const &lhs, Pattern const &rhs)
:
    d_pair(lhs.d_pair),
    d_lopRhs(new Pattern(rhs))
{}
