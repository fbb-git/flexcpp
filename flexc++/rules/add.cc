#include "rules.ih"

void Rules::add(Pair const &pair, size_t accept, string const &action)
{
    d_rules.push_back( {pair.first, accept, action} );
    size_t sc = d_rules.size() - 1;

    d_reverse[pair.second] = sc;

    if (accept)
        d_reverseAccept[accept] = sc;

    d_startConditions.add(sc);
}    
