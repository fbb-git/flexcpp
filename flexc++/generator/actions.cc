#include "generator.ih"

void Generator::actions(ostream &out) const
{
    key(out);

    set<size_t> done;
    done.insert(UINT_MAX);                  // Filler for non-FINAL rows

//    ofstream out("ACTIONS");

    for_each(d_dfas.begin(), d_dfas.end(), 
            FnWrap::unary(dfaActions, out, done));
}
