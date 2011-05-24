#include "scanner.ih"

void Scanner::begin(StartCondition__ to)
{
    d_fromCondition.push(startCondition());
    ScannerBase::begin(to);
}
