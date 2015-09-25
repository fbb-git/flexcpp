#include "options.ih"

void Options::setParserInfo(string const &matched, string const &rawString)
{
    d_matched = &matched;
    d_rawString = &rawString;
}

