#include "generator.ih"

string Generator::outDFAbase([[maybe_unused]] string const &startState, 
                             size_t offset)
{
    string ret = "    s_dfa_ + " + to_string(offset) + ",";
    return ret;
}
