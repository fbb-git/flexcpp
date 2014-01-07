#include "pattern.ih"

Pattern &Pattern::operator=(Pair const &pair)
{
    d_pair = pair;
    d_lopData.reset();
    return *this;
}
