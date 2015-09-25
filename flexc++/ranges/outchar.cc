#include "ranges.ih"

void Ranges::outChar(std::ostream &out, size_t idx)
{
    out << setw(3) << idx;

    if (isprint(idx))
        out << "('" << static_cast<char>(idx) << "')";
    else
        out << "     ";            
}
