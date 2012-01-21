#include "scanner.ih"

void Scanner::reset(StartCondition__ to)
{
    d_fromCondition = stack<StartCondition__>();

    if (to != StartCondition__::INITIAL)
        d_fromCondition.push(startCondition());

    if (to == StartCondition__::pattern)
        d_beginOfPattern = true;

    ScannerBase::begin(to);
}
