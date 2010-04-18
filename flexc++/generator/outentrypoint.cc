#include "generator.ih"

string Generator::outEntryPoint(string const &startState, size_t offset)
{
    string ret = "        { Begin::" + startState + ", "
                            "s_dfa + " + X2a(offset).str() + " },";
    return ret;
}






