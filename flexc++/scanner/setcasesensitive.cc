#include "scanner.hh"

void Scanner::setCaseSensitive()
{
    d_caseSensitive = Options::instance().caseSensitive();
}


