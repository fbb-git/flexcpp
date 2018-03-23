#include "scanner.ih"

void Scanner::newDefinition()
{
    d_patternName.clear();
    push(StartCondition_::line);
}

