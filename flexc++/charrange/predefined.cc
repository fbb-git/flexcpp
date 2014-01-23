#include "charrange.ih"

// this function returns the set of characters that are defined by a
// predefined setname.
// To determine the set of characters s_hash is used. It is an unordered_map
// initialized to an empty set in `data.cc', and it is filled with its
// characters the first time it is used. At the same time the negated set is
// filled. 

set<char> const &CharRange::predefined(std::string const &setName)
{
    size_t const beyond = max<unsigned char>() + 1;

    auto &chSet = s_hash[setName];

    if (chSet.empty())
    {
        if (setName == ".")
        {
            copy(AllChars(0), AllChars(beyond), inserter(chSet, chSet.end()));
            chSet.erase('\n');
            return chSet;
        }

        string setToFill = setName;
        string complementedSet = setToFill;

        if (setToFill[2] != '^')
            complementedSet.insert(2, 1, '^');
        else
            setToFill.erase(2, 1);

        auto &fillSet = s_hash[setToFill];
        auto fillFun = s_funHash[setToFill];

        for (size_t idx = 0; idx != beyond; ++idx)
            if (fillFun(idx))
                fillSet.insert(idx);

        s_hash[complementedSet] = negate(fillSet);
    }
    return chSet;
}
