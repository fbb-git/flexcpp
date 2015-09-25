#include "charclass.ih"

void CharClass::append(vector<string> const &strings)
{
    for (auto &str: strings)
    {
        if (str[0] == 'p')
        {
            if (d_type.back().second != PREDEF)
               d_type.push_back({d_str.length(), PREDEF});
        }
        else
        {
            if (d_type.back().second != CHAR)
                d_type.push_back({d_str.length(), CHAR});
        }
        d_str.append(str.begin() + 1, str.end());   // add all but the 1st
    }
}


