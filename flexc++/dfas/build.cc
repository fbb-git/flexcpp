#include "dfas.ih"

void DFAs::build()
{
    for_each(d_rules.begin(), d_rules.end(), 
            FnWrap::unary(buildDFA, *this));
}
