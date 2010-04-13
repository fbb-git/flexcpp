#include "charrange.ih"

set<char> const &CharRange::predefined(std::string const &setName)
{
    auto &chSet = s_hash[setName];

    if (chSet.empty())
    {
        string fillName = setName;
        string negated = fillName;

        if (fillName[2] != '^')
            negated.insert(2, 1, '^');
        else
            fillName.erase(2);

        auto &fillSet = s_hash[fillName];
        auto fillFun = s_funHash[fillName];

        for (size_t idx = 0; idx < UCHAR_MAX; ++idx)
            if (fillFun(idx))
                fillSet.insert(idx);

        s_hash[negated] = negate(fillSet);
    }
    return chSet;
}
