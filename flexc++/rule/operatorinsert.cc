#include "rule.ih"

#include <ostream>
#include <iterator>
#include <iomanip>

ostream &operator<<(ostream &out, Rule const &rule)
{
    out << " (" << rule.d_source << " " << rule.d_lineNr << 
                "). Startstate " << setw(2) << rule.startState();

    return out;
}
