#include "charclass.ih"

bool CharClass::rangeAfterRange(TagIter iter) const
{
    if 
    (
        iter + 1  != d_tag.end()            // another - exists
        && 
        *iter + 2 == *(iter + 1)    // saw 'a-b-': illegal pattern
    )
    {
        emsg << "range '-' cannot follow range `" << 
                                        rangeString(*iter) << '\'' << endl;
        return true;
    }

    return false;
}
