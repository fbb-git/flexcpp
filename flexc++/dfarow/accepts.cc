#include "dfarow.ih"

string DFARow::accepts() const
{
    ostringstream out;

//X    for_each(d_acceptRule.begin(), d_acceptRule.end(),
//X        FnWrap::unary(outAccept, out, *this));

    return out.str();
}
