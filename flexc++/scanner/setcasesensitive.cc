#include "scanner.ih"

void Scanner::setCaseSensitive()
{
    d_caseSensitive = Options::instance().caseSensitive();
}


