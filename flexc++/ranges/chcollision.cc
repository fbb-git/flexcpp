#include "ranges.hh"

bool Ranges::chCollision(unsigned char ch, unsigned char &pre, 
                                        size_t const *next)
{
    if (pre + 1 == ch)              // in a range
    {
        pre = ch;
        return false;               // report `no collision'
    }

        // no range, do the post-test for pre and the pre-test for ch
    return     
            next[pre] == next[pre + 1]
        ||
            next[ch - 1] == next[ch];
}
