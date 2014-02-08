#include "charrange.ih"

// this function returns the set of characters that are defined by a
// predefined setname.
// To determine the set of characters s_hash is used. It is an FBB::LinearMap
// initialized to an empty set in `data.cc', and it is filled with its
// characters the first time it is used. At the same time the negated set is
// filled. 

string const &CharRange::predefined(std::string const &setName)
{
    size_t const beyond = FlexTypes::NCHARS;

    auto &str = s_hash[setName];

    if (str.empty())
    {
        if (setName == ".")
        {
            for (size_t begin = 0; begin != '\n'; ++begin)
                str += begin;
            for (size_t begin = '\n' + 1; begin != beyond; ++begin)
                str += begin;

            return str;
        }

        string setToFill = setName;
        string complementedSet = setToFill;

//cerr << "Range: predef\n";

        if (setToFill[2] != '^')
            complementedSet.insert(2, 1, '^');
        else
            setToFill.erase(2, 1);

        auto &fillSet = s_hash[setToFill];
        auto fillFun = s_funHash[setToFill];

//cerr << "Range: predef\n";

        for (size_t idx = 0; idx != beyond; ++idx)
            if (fillFun(idx))
                fillSet += idx;

//cerr << "Range: predef\n";

        s_hash[complementedSet] = negate(fillSet);

//cerr << "Range: predef\n";
    }
    return str;
}

