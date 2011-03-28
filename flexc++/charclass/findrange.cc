#include "charclass.ih"

size_t CharClass::findRange(size_t from) const
{
    auto iter = d_chars.begin() + from;

    while (true)
    {                                   // find a - not in a predef'd range
        auto minus = find(iter, d_chars.end(), pair<char, bool>('-', false));

        if (minus == iter)              // - cannot be the very first char.
        {
            ++iter;
            continue;
        }

        if (minus == d_chars.end())     // none found
          return 0;

//cout << "FINDRANGE: #chars = " << d_chars.size() << '\n';
        return minus - d_chars.begin();

    }
}




