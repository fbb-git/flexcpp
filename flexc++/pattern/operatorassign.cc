#include "pattern.ih"

Pattern &Pattern::operator=(Pair const &pair)
{
    d_pair = pair;
    d_lopRhs.reset();
    return *this;
}
