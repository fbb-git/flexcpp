#include "scanner.ih"

void Scanner::reset(StartCondition to)
{
    d_fromCondition = stack<StartCondition>();

    if (to != INITIAL)
        d_fromCondition.push(startCondition());

    if (to == pattern)
        d_beginOfPattern = true;

    ScannerBase::begin(to);
}
