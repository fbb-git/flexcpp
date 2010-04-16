#include "dfarow.ih"

void DFARow::setInheriting()
{
    unordered_map<size_t, size_t> dest;

    transform(d_acceptRules.begin(), d_acceptRules.end(), 
            inserter(dest, dest.end()), toInheriting);

    d_acceptRules = dest;
}
