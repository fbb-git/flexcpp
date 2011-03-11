#include "generator.ih"

string Generator::outDFAbase(string const &startState, size_t offset)
{
    string ret = "    s_dfa + " + X2a(offset).str() + ",";
    return ret;
}






