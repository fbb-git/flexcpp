#include "charclass.hh"

string const &CharClass::str()
{
    if (d_state != FINAL)        
    {
        std::set<char> const &tmp = set();
        d_str.assign(tmp.begin(), tmp.end());
        d_state = FINAL;
    }
    return d_str;
}
