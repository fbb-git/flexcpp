#include "charclass.ih"

bool CharClass::inversedRange(size_t idx) const
{
    if 
    (                                       // first char must be <= last ch.
        static_cast<unsigned char>(d_chars[idx - 1].first) 
        > 
        static_cast<unsigned char>(d_chars[idx + 1].first)
    )
    {
        emsg << "lllegal range: `" << rangeString(idx) << '\'' << endl;
        return true;
    }

    return false;
}
