#include "charclass.hh"

std::ostream &operator<<(std::ostream &out, CharClass const &cc)
{
    bool onlyPrintable = true;

    for (char ch: cc.d_str)
    {
        if (isprint(ch))
            out << ch;
        else
            onlyPrintable = false;
    }
    if (onlyPrintable)
        return out;

    out << " #";
    for (char ch: cc.d_str)
    {
        if (not isprint(ch))
            out << '#' << (int)ch;
    }
    return out;
}
