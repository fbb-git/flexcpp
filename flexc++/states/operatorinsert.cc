#include "states.ih"

#include <ostream>
#include <iomanip>

ostream &operator<<(ostream &out, States const &states)
{
    out << 
        " E: EMPTY, F: FINAL, S: SET, <nr>: range\n"
        " NR  TYPE   F   N1 N2 [range-indices]\n"
        "---------------------------------------------------\n";
    for (size_t idx = 0, end = states.size(); idx != end; ++idx)
    {
        if (states[idx].type() != State::UNDETERMINED__)
            out << setw(3) << idx << ": " << states[idx] << '\n';
    }
    return out;
}
