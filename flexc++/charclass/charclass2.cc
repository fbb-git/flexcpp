#include "charclass.ih"

inline CharClass::CharClass(string const &match)
{
    string str;
    vector <size_t> minus;

    size_t begin = 0;
    size_t idx = 0;                       // push \- delimited substrings
    while ((idx = match.find("\\", idx)) != string::npos)
    {
        if (match[idx + 1] != '-')
        {
            idx += 2;
            continue;
        }

        addSet(
            minus, 
            str.length(), 
            String::unescape(match.substr(begin, idx - begin))
        );

        d_chars.push_back({'-', CHAR});     // add - as a character

        idx += 2;
        begin = idx;
    }

    addSet(
        minus, 
        str.length(), 
        String::unescape(match.substr(begin, string::npos))
    );

    for (size_t idx: minus)
        d_chars[idx].second = MINUS;
}


