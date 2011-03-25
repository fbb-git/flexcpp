#include "charclass.ih"

size_t CharClass::findRange(size_t from) const
{
    ++from;                             // 'a-b...': start looking at next idx

    if (from < d_chars.size())          // search for 'a-b' patterns
    {
        from = d_chars.find('-', from); // look for a '-'

        if (from < d_chars.size() - 1)  // got a '-' and a character beyond
            return from;
    }
    return 0;                           // not found
}
