#include "rules.ih"

size_t Rules::add(Pair const &pair, size_t accept, string const &action)
{
    d_rules.push_back( {pair.first, accept, action} );
    size_t ret = d_rules.size() - 1;

    d_reverse[pair.second] = ret;
    return ret;
}    
