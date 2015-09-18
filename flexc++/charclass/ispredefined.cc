#include "charclass.hh"

bool CharClass::isPredefined(size_t idx) const
{
    return find_if(d_type.begin(), d_type.end(),
                [&](std::pair<size_t, CharType> const &pair)
                {
                    return pair.second == PREDEF && pair.first == idx;
                }
            ) != d_type.end();
}

