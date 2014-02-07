#include "charclass.ih"

void CharClass::append(vector<string> const &strings)
{
    for (auto &str: strings)
    {
        if (str[0] == 'p')
        {
            if (d_type.back().second != 'p')
               d_type.push_back({d_str.length(), PREDEF});
        }
        else
        {
            if (d_type.back().second != 'n')
                d_type.push_back({d_str.length(), CHAR});
        }
        d_str += str;
    }
}


