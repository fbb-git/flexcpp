#include "scanner.hh"

void Scanner::newDefinition()
{
    d_patternName.clear();
    push(StartCondition__::line);
}

