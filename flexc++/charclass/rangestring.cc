#include "charclass.ih"

string CharClass::rangeString(size_t idx) const
{
    string ret;

    char ch = d_chars[idx - 1].first;

    if (isprint(ch))
        ret = ch;
    else
        ret = "(int)" + to_string(static_cast<int>(ch));

    ret += '-';

    ch = d_chars[idx + 1].first;

    if (isprint(ch))
        ret += ch;
    else
        ret += "(int)" + to_string(static_cast<int>(ch));

    return ret;
}
