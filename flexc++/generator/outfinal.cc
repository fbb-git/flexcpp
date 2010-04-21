#include "generator.ih"

void Generator::outFinal(size_t rule, ostream &out, size_t &count)
{
    out << rule << ", ";
    if (++count % 20 == 0)
        out << "\n"
                "         ";
}
