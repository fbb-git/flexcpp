#include "generator.ih"

string Generator::outEntryPoint(string const &startState, size_t offset)
{
    string ret = '{' + startState + ',' + X2a(offset).str() + "},";
    return ret;
}






