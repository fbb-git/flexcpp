#include "dfarow.ih"

string DFARow::accepts() const
{
    ostringstream out;

    for_each(d_acceptRule.begin(), d_acceptRule.end(),
        FnWrap::unary(outAccept, out, *this));

    return out.str();
}
