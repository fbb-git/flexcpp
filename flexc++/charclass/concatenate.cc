#include "charclass.ih"

CharClass CharClass::concatenate(CharClass const &left, 
                                  CharClass const &right)
{
    CharClass ret(left);

    Vector &lhs = ret.d_chars;

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

    return ret;    
}


