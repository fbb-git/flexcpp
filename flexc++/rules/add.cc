#include "rules.ih"

size_t Rules::add(size_t beginState, size_t accept, string const &action)
{
    d_rules.push_back( {beginState, accept, action} );
    return d_rules.size() - 1;
}    
