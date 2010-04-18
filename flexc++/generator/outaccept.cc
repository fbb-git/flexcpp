#include "generator.ih"

void Generator::outAccept(Pair const &pair, ostream &out, size_t &count)
{
    out << "{'" << 
            (pair.second == State::INHERITING ? 'I' : 'N') << "'," << 
            pair.first << "}, ";
    if (++count % 8 == 0)
        out << "\n"
                "         ";
}
