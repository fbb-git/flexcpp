#include "ranges.ih"

#include <ostream>
#include <iomanip>
#include <cctype>

ostream &operator<<(ostream &out, Ranges const &ranges)
{
    out << "Nsubsets: " << ranges.size() << '\n';

    for (size_t idx = 0, last = UINT_MAX, count = 0; idx < 256; ++idx)
    {
        if (ranges.rangeOf(idx) != last)
        {
            last = ranges.rangeOf(idx);

            if (idx != 0)
            {
                out << " - ";
    
                out << setw(3) << idx - 1;
                if (isprint(idx - 1))
                    out << "('" << static_cast<char>(idx - 1) << "')";
                else
                    out << "     ";
                out << '\n';
            }

            out << setw(2) << ++count << ": " << setw(3) << idx;
            if (isprint(idx))
                out << "('" << static_cast<char>(idx) << "')";
            else
                out << "     ";
        }
    }

    out << " - 255\n";

    if (size_t bol = ranges.rangeOfBOL())
        out << "BOL: " << bol << '\n';

    if (size_t eof = ranges.rangeOfEOF())
        out << "EOF: " << eof << '\n';

    return out;
}

