#include "charclass.ih"

set<char> CharClass::set() const
{
    std::set<char> dest;

    size_t start = 0;                   // ranges don't start at idx 0
    while (true)
    {
        size_t idx = findRange(start);  // at idx-1: 'a-b' (beyond 'start')

        if (idx == 0)                           // no 'a-b' range found
            break;

        if (a_b_c(idx))                         // Error pattern a-b-c
            return dest;

        addIndices(dest, start, idx - 1);       // add fm 'start' to 'idx - 1'
        addRange(dest, idx);                    // add the range of chars

        start = idx + 2;                        // continue beyond the range
    }
    addIndices(dest, start, d_chars.size());    // add the remaining chars

    return dest;
}



