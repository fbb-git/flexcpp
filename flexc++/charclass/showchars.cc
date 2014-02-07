#include "charclass.ih"

void CharClass::showChars(char const *label) const
{
    cout << "CharClass " << label << '\n';

    for (auto pair: d_chars)
        if (isprint(pair.first))
            cout << pair.first << " (" << pair.second << ") ";

    cout << '\n';

    for (auto pair: d_chars)
        if (not isprint(pair.first))
            cout << (int)pair.first << " (" << pair.second << ") ";

    cout << '\n';
}
