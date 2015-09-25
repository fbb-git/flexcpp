#include "charclass.ih"

string CharClass::rangeString(size_t idx) const
{
    string ret;

    char ch = d_str[idx - 1];

    if (isprint(ch))
        ret = ch;
    else
        ret = "(int)" + to_string(static_cast<int>(ch));

    ret += '-';

    ch = d_str[idx + 1];

    if (isprint(ch))
        ret += ch;
    else
        ret += "(int)" + to_string(static_cast<int>(ch));

    return ret;
}
