#include "charrange.ih"

string CharRange::negate(string const &str)
{
    static string  
            all(numeric_limits<char>::min(), numeric_limits<char>::max());

    string ret(FlexTypes::NCHARS, 0);

    auto end = set_difference(all.begin(), all.end(), str.begin(), str.end(),
                              ret.begin());

    ret.resize(end - ret.begin());
    return ret;
}
