#include "charclass.ih"

spSemVal &CharClass::concatenate(spSemVal &left, SemVal const &right)
{
    Vector &lhs = downCast<CharClass>(*left).d_chars;
    Vector const &rhs = downCast<CharClass>(right).d_chars;

<<<<<<< HEAD
//    cout << "CONCAT: left = ";
//    display(lhs);
//    cout << "right = ";
//    display(rhs);

    copy(rhs.begin(), rhs.end(), back_inserter(lhs));

//    cout << "out = ";
//    display(lhs);
//    cout << downCast<CharClass>(*left).str() << '\n';
//    cout << "CONCAT OUT\n";
=======
    lhs.d_chars += rhs.d_chars;

>>>>>>> 567a1f0b905ae51a6602f06840bf0ce865ecf5e9
    return left;    
}


