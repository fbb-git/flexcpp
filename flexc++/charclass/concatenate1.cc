#include "charclass.ih"

void CharClass::concatenate1(CharClass &lhs, std::string const &rChars)
{
    if (rChars.length() == 1)       // README cell[1][0]: 
        lhs.d_last += rChars;           //  add single rhs char to lhs

    else if (rChars[0] == '-')      // README cell[1][1], process a range
    {                                               
        lhs.addRange(lhs.d_last[0], rChars[1]);     // add it to lset
        lhs.d_last.clear();                         // pending chars processed
    }                                               

    else                            // README cell[1][1], no range
    {                                               
        lhs.addSet(lhs.d_last);                     // add lhs chars to set
        lhs.d_last = rChars;                        // cp rChars to lhs
    }
}
