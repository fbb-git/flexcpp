#include "charrange.ih"

string CharRange::negate(string const &str)
{
    string all(FlexTypes::NCHARS, 0);
    char ch = numeric_limits<char>::min();
    for (char &c: all)
        c = ch++;

    string ret(FlexTypes::NCHARS, 0);

    auto end = set_difference(all.begin(), all.end(), str.begin(), str.end(),
                              ret.begin());

    ret.resize(end - ret.begin());

    return ret;
}
