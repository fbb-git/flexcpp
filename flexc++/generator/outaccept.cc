#include "generator.ih"

void Generator::outAccept(Pair const &pair, ostream &out, size_t &count)
{
    out << pair.first << ", ";
    if (++count % 20 == 0)
        out << "\n"
                "         ";
}
