#include "charclass.ih"

string const &CharClass::str()
{
//    cout << "CHARCLASS: str.cc RAW: " << *this << '\n';

    if (d_state != FINAL)        
    {
        std::set<char> const &tmp = set();
        d_str.assign(tmp.begin(), tmp.end());
    }

    return d_str;
}
