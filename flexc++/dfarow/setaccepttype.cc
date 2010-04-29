#include "dfarow.ih"

void DFARow::setAcceptType()
{
    for_each(d_acceptRule.begin(), d_acceptRule.end(),
        FnWrap::unary(nextAcceptType, *this));
}
