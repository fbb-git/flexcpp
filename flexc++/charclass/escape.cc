#include "charclass.ih"

CharClass CharClass::escape(string const &match)
{
    vector<string> substr;

    size_t begin = 0;
    size_t idx = 0;                       // push \- delimited substrings
    while ((idx = match.find("\\", idx)) != string::npos)
    {
        if (match[idx + 1] != '-')
        {
            idx += 2;
            continue;
        }

        substr.push_back(
                    String::unescape(match.substr(begin, idx - begin)));

        idx += 2;
        begin = idx;
    }

    substr.push_back(String::unescape(match.substr(begin, string::npos)));

    string str = substr[0];

    for (idx = 1; idx != substr.size(); ++idx)
        str += "\\-" + substr[idx];

    CharClass ret(str);
    return ret;
}
