#include "generator.ih"

void Generator::actions(DFAs const &dfas)
{
    d_out.close();
    Msg::open(d_out, "ACTIONS");

    set<size_t> done;
    done.insert(UINT_MAX);                  // Filler for non-FINAL rows

    for_each(dfas.begin(), dfas.end(), 
            FnWrap::unary(dfaActions, d_out, done));
}
