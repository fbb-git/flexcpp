#include "charrange.hh"

string CharRange::negate(string const &str)
{
    string ret(FlexTypes::NCHARS, 0);

    auto end = set_difference(s_all.begin(), s_all.end(), 
                                str.begin(), str.end(),
                                ret.begin());

    ret.resize(end - ret.begin());

    return ret;
}
