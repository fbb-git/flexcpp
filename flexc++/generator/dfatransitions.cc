#include "generator.hh"

void Generator::dfaTransitions(DFARow const &row, ostream &out)
{
    for (size_t idx = 0, end = row.size(); idx != end; )
    {
        auto iter = row.map().find(idx);
        if (iter == row.map().end())
            out << "-1,";
        else
            out << setw(2) << iter->second << ',';

        if (++idx % 20 == 0)
            out << "\n"
                   "         ";                   
    }
}

