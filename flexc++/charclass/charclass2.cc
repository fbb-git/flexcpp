#include "charclass.ih"

CharClass::CharClass(string const &match)
{
    string str;
    size_t length = 0;
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

        str += String::unescape(match.substr(begin, idx - begin));
        addMinuses(minus, length, str);
        str += '-';                         // add - as a character

        idx += 2;
        begin = idx;
        length = str.length();
    }

    str += String::unescape(match.substr(begin, string::npos));
    addMinuses(minus, length, str);

    for (char ch: str)
        d_chars.push_back({ch, CHAR});

    for (size_t idx: minus)
        d_chars[idx].second = MINUS;


//cout << "CharClass OUT\n";
//for (auto pair: d_chars)
//    if (isprint(pair.first))
//        cout << pair.first << " (" << pair.second << ") ";
//cout << ' ';
//for (auto pair: d_chars)
//    if (not isprint(pair.first))
//        cout << (int)pair.first << " (" << pair.second << ") ";
//cout << '\n';

}
