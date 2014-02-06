#include "charclass.ih"

bool CharClass::rangeAfterRange(size_t idx) const
{
    if 
    (
        idx + 2 < d_chars.size()            // 'X' in 'a-bX' exists
        && 
        d_chars[idx + 2].second == RANGE    // saw 'a-b-': illegal pattern
    )
    {
        emsg << "range '-' cannot follow range `" << 
                                        rangeString(idx) << '\'' << endl;
        return true;
    }

    return false;
}
