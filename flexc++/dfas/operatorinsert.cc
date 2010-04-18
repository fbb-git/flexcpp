#include "dfas.ih"

ostream &operator<<(ostream &out, DFAs const &dfas)
{
    for_each(dfas.d_dfa.begin(), dfas.d_dfa.end(), 
                                FnWrap::unary(DFAs::showDFA, out));
    return out;
}
