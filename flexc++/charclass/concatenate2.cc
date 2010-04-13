#include "charclass.ih"

// lhs length == 2

void CharClass::concatenate2(CharClass &lhs, std::string const &rChars)
{
    if (rChars.length() == 1)           // README cell[2][0]: range in d_last
    {
        if (lhs.d_last[1] == '-')           // range with rChars
        {
            lhs.addRange(lhs.d_last[0], rChars[0]);
            lhs.d_last.clear();
        }
        else                                // no range, swallow rChars
        {
            lhs.addSet(lhs.d_last);
            lhs.d_last = rChars;
        }
    }

    else if (lhs.d_last[1] == '-')      // README cell[2][1], range in d_last
    {
        lhs.addRange(lhs.d_last[0],rChars[0]);  // add the range
        lhs.d_last = rChars[1];                 // one more char. to process
    }
    else                                // no range in d_last
    {
        lhs.d_set.insert(lhs.d_last[0]);    // add d_last[0] to d_set

        if (rChars[0] == '-')                   // range in rChars
        {
            lhs.addRange(lhs.d_last[1], rChars[1]);     // add to d_set
            lhs.d_last.clear();                         // clear d_last
        }
        else                                    // no range
        {
            lhs.d_set.insert(lhs.d_last[1]);            // add d_last to d_set
            lhs.d_last = rChars;                        // swallow rChars
        }
    }
}

