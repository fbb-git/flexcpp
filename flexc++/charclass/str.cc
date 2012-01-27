#include "charclass.ih"

string CharClass::str() const
{
//    cout << "STR RAW: ";
//    display(d_chars);
        
    std::set<char> const &tmp = set();

    string ret(tmp.begin(), tmp.end());
    return ret;
}
