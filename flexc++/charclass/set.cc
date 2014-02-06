#include "charclass.ih"

set<char> CharClass::set() const
{
    std::set<char> dest;

    if (d_chars.empty() == 0)
        return dest;

    if (d_chars.front().second == MINUS)        // first/last chars are never
        d_chars.front().second = CHAR;          // RANGE minuses.

    if (d_chars.back().second == MINUS)
        d_chars.back().second = CHAR;

    size_t start = 1;
    while (size_t idx = findRange(start))       // find the next RANGE 
    {
        if (not validRange(idx))                // Error pattern a-b-c or 
            return dest;                        // bordering predefined

        addChars(dest, start, idx - 1);         // add fm 'start' to 'idx - 1'
        addRange(dest, idx);                    // add the range of chars

        start = min(d_chars.size(), idx + 2);   // continue beyond the range
    }
    addChars(dest, start, d_chars.size());      // add the remaining chars

//    cout << "SET OUT\n";

    return dest;
}





