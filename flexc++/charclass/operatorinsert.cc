#include "charclass.ih"

std::ostream &operator<<(std::ostream &out, CharClass const &cc)
{
    for (auto &cb: cc.d_chars)
    {
        char c = cb.first;
        if (isprint(c))
            out << c;
        else
            out << ' ' << (int)c << ' ';
    }
    return out;
}
