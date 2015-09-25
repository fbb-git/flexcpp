#include "dfas.ih"

DFAs::~DFAs()
{
    for (auto &pair: d_dfa)
        delete pair.second;
}
