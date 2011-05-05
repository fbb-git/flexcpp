#include "charclass.ih"

    // got a pattern 'a-b', idx at '-'
bool CharClass::validRange(size_t idx) const 
{
    if (d_chars[idx - 1].second)        // no predef'd range before '-'
    {
        emsg << "'-' cannot follow predefined set" << endl;
        return false;
    }
                                        // no predef'd range beyond '-'
    if (idx + 1 < d_chars.size() && d_chars[idx + 1].second)
    {
        emsg << "predefined set cannot follow '-'" << endl;
        return false;
    }

    string range(1, d_chars[idx - 1].first);
    range += '-';
    range += d_chars[idx + 1].first;

    if 
    (
        idx + 3 < d_chars.size()        // 'a-b..' exists
        && 
        d_chars[idx + 2].first == '-'   // and saw 'a-b-', so illegal pattern
    )
    {
        emsg << "'-' cannot follow range `" << range << '\'' << endl;
        return false;       // saw 'a-b-c'
    }
                                        // reversed ordering
    if 
    (
        idx + 1 < d_chars.size() 
        &&
        static_cast<unsigned char>(d_chars[idx - 1].first) > 
        static_cast<unsigned char>(d_chars[idx + 1].first)
    )
    {
        emsg << "lllegal range: `" << range << '\'' << endl;
        return false;
    }

    return true;            // legal range
}




