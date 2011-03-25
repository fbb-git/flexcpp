#include "rule.ih"

#include <ostream>
#include <iterator>
#include <iomanip>

ostream &operator<<(ostream &out, Rule const &rule)
{
    out << " (" << rule.d_source << " " << rule.d_lineNr << 
                "). Startstate " << setw(2) << rule.startState();

    if (size_t accept = rule.accept())
    {
        out << " (" << accept << ") ";
        copy(rule.d_postAstates.begin(), rule.d_postAstates.end(), 
                ostream_iterator<size_t>(out, ","));
    }
    return out;
}
