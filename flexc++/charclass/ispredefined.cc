#include "charclass.ih"

bool CharClass::isPredefined(size_t idx) const
{
    cerr << "is predef " << idx << '\n';

    return find_if(d_type.begin(), d_type.end(),
                [&](std::pair<size_t, CharType> const &pair)
                {
//cerr << "comparing to " << pair.first << ", " << pair.second << '\n';
                    return pair.second == PREDEF && pair.first == idx;
                }
            ) != d_type.end();
}

