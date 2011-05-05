#include "charclass.ih"

spSemVal &CharClass::concatenate(spSemVal &left, SemVal const &right)
{
    Vector &lhs = downCast<CharClass>(*left).d_chars;
    Vector const &rhs = downCast<CharClass>(right).d_chars;

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


