#include "rules.ih"

#include <ostream>

ostream &operator<<(ostream &out, Rules const &rules)
{
    for (size_t idx = 0, end = rules.d_rules.size(); idx != end; ++idx)
        out << idx << ": " << rules[idx] << '\n';

    return out;
}
