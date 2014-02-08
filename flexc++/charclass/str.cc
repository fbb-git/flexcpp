#include "charclass.ih"

string const &CharClass::str()
{
//cerr << "CHARCLASS: str.cc RAW: " << *this << '\n';

    if (d_state != FINAL)        
    {
        std::set<char> const &tmp = set();
        d_str.assign(tmp.begin(), tmp.end());
        d_state = FINAL;
    }

//cerr << "CHARCLASS: str.cc FINAL: " << *this << '\n';

    return d_str;
}
