#include "charclass.ih"

bool CharClass::a_b_c(size_t idx) const // got a pattern 'a-b', idx at '-'
{
    if 
    (
        idx + 3 < d_chars.size()        // 'a-b..' exists
        && 
        d_chars[idx + 2] == '-'         // and saw 'a-b-', so illegal pattern
    )
    {
        emsg << "Illegal character set `" << d_chars.substr(idx-1, idx+3)  << 
                                                                '\'' << endl;
        return true;    // saw 'a-b-c'
    }
    return false;       // not 'a-b-c'
}
