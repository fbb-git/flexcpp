#include "charclass.ih"

CharClass &CharClass::concatenate(CharClass &left, CharClass const &right)
{
    Vector &lhs = left.d_chars;
    Vector const &rhs = right.d_chars;

//    cout << "CONCAT: left = ";
//    display(lhs);
//    cout << "right = ";
//    display(rhs);

    copy(rhs.begin(), rhs.end(), back_inserter(lhs));

//    cout << "out = ";
//    display(lhs);
//    cout << downCast<CharClass>(*left).str() << '\n';
//    cout << "CONCAT OUT\n";

//    lhs += rhs;

    return left;    
}


