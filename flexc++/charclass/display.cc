#include "charclass.ih"

void CharClass::display(Vector const &vect)
{
    for (auto begin = vect.begin(), end = vect.end(); begin != end;
        ++begin)
    {
        char c = begin->first;
        if (isprint(c))
            cout << c;
        else
            cout << ' ' << (int)c << ' ';
    }
    cout << '\n';
}
