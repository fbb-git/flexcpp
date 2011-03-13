#include "generator.ih"

void Generator::actions(DFAs const &dfas)
{
    set<size_t> done;
    done.insert(UINT_MAX);                  // Filler for non-FINAL rows

    ofstream out("ACTIONS");

    for_each(dfas.begin(), dfas.end(), 
            FnWrap::unary(dfaActions, out, done));
}
