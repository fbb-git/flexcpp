#include "charclass.ih"

// See README for a description
    
spSemVal &CharClass::concatenate(spSemVal &left, SemVal const &right)
{
    CharClass &lhs = downCast<CharClass>(*left);
    CharClass const &rhs = downCast<CharClass>(right);

    lhs.addSet(rhs.d_set);                   // add rhs.set 

    switch (lhs.d_last.length())
    {
        case 0:                             // README: row[0]
            lhs.d_last = rhs.d_last;
        break;

        case 1:                             // README: row[1]
            concatenate1(lhs, rhs.d_last);  
        break;

        case 2:                             // README: row[2]
            concatenate2(lhs, rhs.d_last);
        break;
    }
    return left;    
}
