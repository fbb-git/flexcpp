#include "charrange.ih"

set<char> const &CharRange::predefined(std::string const &setName)
{
    size_t const beyond = UCHAR_MAX + 1;

    auto &chSet = s_hash[setName];

    if (chSet.empty())
    {
        if (setName == ".")
        {
            copy(AllChars(0), AllChars(beyond), inserter(chSet, chSet.end()));
            chSet.erase('\n');
            return chSet;
        }

        string fillName = setName;
        string negated = fillName;

        if (fillName[2] != '^')
            negated.insert(2, 1, '^');
        else
            fillName.erase(2);

        auto &fillSet = s_hash[fillName];
        auto fillFun = s_funHash[fillName];

        for (size_t idx = 0; idx != beyond; ++idx)
            if (fillFun(idx))
                fillSet.insert(idx);

        s_hash[negated] = negate(fillSet);
    }
    return chSet;
}
