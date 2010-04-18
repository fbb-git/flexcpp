#include "dfas.ih"

DFAs::DFAInfo::const_iterator DFAs::find(std::string const &key) const
{
    return find_if(d_dfa.begin(), d_dfa.end(), FnWrap::unary(findKey, key));
}
        
