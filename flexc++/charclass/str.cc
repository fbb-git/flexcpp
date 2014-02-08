#include "charclass.ih"

string const &CharClass::str()
{
    cerr << "CHARCLASS: str.cc RAW: " << *this << '\n';

    for (auto &tpe: d_type)
        cerr << tpe.first << ' ' << tpe.second << ", ";
    cerr << '\n';

    if (d_state != FINAL)        
    {
        std::set<char> const &tmp = set();
        d_str.assign(tmp.begin(), tmp.end());
    }

    cerr << "CHARCLASS: str.cc FINAL: " << *this << '\n';

    return d_str;
}
