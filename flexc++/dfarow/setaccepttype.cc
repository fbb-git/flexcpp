//X#include "dfarow.ih"
//X
//Xvoid DFARow::setAcceptType()
//X{
//X    for_each(d_acceptRule.begin(), d_acceptRule.end(),
//X        FnWrap::unary(nextAcceptType, *this));
//X}
