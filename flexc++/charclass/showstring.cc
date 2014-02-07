#include "charclass.ih"

void CharClass::showString(string const &str, char const *label) const
{
    cout << "CharClass " << label << '\n';

    size_t idx = 0;

    for (char ch: str)
    {
        if (isprint(ch))
            cout << idx << ':' << ch << ' ';
        ++idx;
    }

    cout << '\n';

    idx = 0;
    for (char ch: str)
    {
        if (not isprint(ch))
            cout << idx << ':' << (int)ch << ' ';
        ++idx;
    }

    cout << '\n';
}

