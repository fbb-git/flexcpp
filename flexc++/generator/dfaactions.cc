#include "generator.ih"

void Generator::dfaActions(DFAs::Pair const &dfaPair, ostream &out,
                                                            set<size_t> &done)
{
    for_each(dfaPair.second.begin(), dfaPair.second.end(), 
            FnWrap::unary(outAction, out, done));
}
