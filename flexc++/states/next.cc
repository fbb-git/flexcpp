#include "states.hh"

size_t States::next()
{
    size_t ret;

    if (d_free.empty())
    {
        ret = d_state.size();
        d_state.resize(ret + 1);
    }
    else
    {
        ret = d_free.back();
        d_free.pop_back();
    }
    return ret;
}
