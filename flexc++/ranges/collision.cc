#include "ranges.hh"

// Collision test: a number indicates a character to test. Series of x chars
// indicate a range. p,q,r,s indicate char-values before and after a (series
// of) x values. p may not exist (if an initial x == 0), s may not exist (if a
// final x == 255). These border conditions are handled separately.
//
// Input example:
//      next:   [            ]
//      str:       pxxxq rxs
//      index:      012   3
//
//  Pre test:
//  Initially next[p] and next[0] are compared. If equal, a collision is
// reported. 
//
//  Range test:
//  Range testing starts at str[1]. While in a range (previous + 1 == current)
//  inc. previous and return `no collision'
//  
//  If there's no range (e.g., from s[2] to s[3]), previous has the previous
// character. Report a collision if next[previous] == next[previous + 1] or if
// next[current - 1] == next[current].
//
//  Post test:
// Having walked over the characters s[1] to s[3], report a collision if 
// s[3] != 255 and next[s[3]] == next[s[3] +1]
//
// So: pretest on s[0], rangetest from s[1] to s[3], posttest on s[3]

bool Ranges::collision(std::string const &str, size_t const *next)
{
    unsigned char pre = str[0];         

    if
    (
            // pre-test
        (pre != 0 && next[pre - 1] == next[pre])
        ||
            // range-test
        find_if(
            str.begin() + 1, str.end(), 
            [&, next](unsigned char ch)
            {
                return chCollision(ch, pre, next);
            }
        ) != str.end()
    )
        return true;

        // post-test
    unsigned char last = *str.rbegin();
    return  last != 255 && next[last] == next[last + 1];
}

