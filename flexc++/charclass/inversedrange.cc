#include "charclass.ih"

bool CharClass::inversedRange(size_t idx) const
{
    if 
    (                                       // first char must be <= last ch.
        static_cast<unsigned char>(d_str[idx - 1]) 
        > 
        static_cast<unsigned char>(d_str[idx + 1])
    )
    {
        emsg << "lllegal range: `" << rangeString(idx) << '\'' << endl;
        return true;
    }

    return false;
}
