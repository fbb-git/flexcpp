#include "charclass.ih"

CharClass &CharClass::concatenate(CharClass const &right)
{
    Vector const &rhs = right.d_chars;

//    cout << "CONCAT: left = ";
//    display(lhs);
//    cout << "right = ";
//    display(rhs);

    copy(rhs.begin(), rhs.end(), back_inserter(d_chars));

//    cout << "out = ";
//    display(lhs);
//    cout << downCast<CharClass>(*left).str() << '\n';
//    cout << "CONCAT OUT\n";

    return *this;
}


