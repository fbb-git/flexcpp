#include "charclass.ih"

std::ostream &operator<<(std::ostream &out, CharClass const &cc)
{
    for (char ch: cc.d_str)
    {
        if (isprint(ch))
            out << ch;
        else
            out << ' ' << (int)ch << ' ';
    }
    return out;
}
