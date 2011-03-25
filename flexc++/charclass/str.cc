#include "charclass.ih"

string const &CharClass::str() const
{
    std::set<char> const &tmp = set();
    return d_chars = string(tmp.begin(), tmp.end());
}
