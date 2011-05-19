#include "scanner.ih"

void Scanner::begin(StartCondition to)
{
    d_fromCondition.push(startCondition());
    ScannerBase::begin(to);
}
