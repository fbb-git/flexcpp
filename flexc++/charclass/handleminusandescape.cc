#include "charclass.ih"

void CharClass::handleMinusAndEscape()
{
    string str;
    size_t length = 0;
    vector <size_t> tag;

    if (d_state == RAW)
        d_type.push_back({d_str.length(), END});

    for (
        auto &begin = d_type.begin(), end = d_type.end();
            begin != end; 
                ++begin
    )
        inspect(tag, begin);




    for (auto &pair: d_
    size_t begin = 0;
    size_t idx = 0;                       // push \- delimited substrings






                                            // add any trailing chars fm match
    str += String::unescape(match.substr(begin, string::npos));
    addMinuses(tag, length, str);           // and store their - locations

    for (char ch: str)                      // add all chars in str to d_chars
        d_chars.push_back({ch, CHAR});

    for (size_t idx: tag)                   // change tagged - chars to MINUS
        d_chars[idx].second = MINUS;
}
