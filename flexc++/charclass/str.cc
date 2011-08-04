#include "charclass.ih"

string CharClass::str() const
{
//    cout << "STR RAW: ";
//    display(d_chars);
        
    std::set<char> const &tmp = set();

//    copy(tmp.begin(), tmp.end(), ostream_iterator<char>(cout));
//    cout << '\n';


    string ret(tmp.begin(), tmp.end());
    return ret;
}
