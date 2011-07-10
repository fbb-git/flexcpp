#include "generator.ih"

string Generator::outDFAbase(string const &startState, size_t offset)
{
    string ret = "    s_dfa__ + " + X2a(offset).str() + ",";
    return ret;
}
