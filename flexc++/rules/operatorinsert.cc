#include "rules.ih"

#include <ostream>
#include <iomanip>

ostream &operator<<(ostream &out, Rules const &rules)
{
    for (size_t idx = 0, end = rules.d_rules.size(); idx != end; ++idx)
        out << setw(2) << idx << ": " << rules[idx] << '\n';

    return out;
}
