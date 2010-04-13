#include "rules.ih"

size_t Rules::add(size_t beginState, size_t accept, bool inheriting, 
                                                    string const &action)
{
    d_rules.push_back( {beginState, accept, inheriting, action} );
    return d_rules.size() - 1;
}    
