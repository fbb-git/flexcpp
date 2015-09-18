#include "dfas.hh"

DFAs::~DFAs()
{
    for (auto &pair: d_dfa)
        delete pair.second;
}
