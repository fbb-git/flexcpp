#include "generator.ih"

void Generator::dfaRow(DFARow const &row, ostream &out, PVector &accept)
{
    out << "        {";

    for (size_t idx = 0, end = row.size(); idx != end; )
    {
        auto iter = row.map().find(idx);
        if (iter == row.map().end())
            out << "-1,";
        else
            out << setw(2) << iter->second << ',';

        if (++idx % 15 == 0)
            out << "\n"
                   "         ";                   
    }

    size_t begin = accept.size();

    out << setw(2) << static_cast<int>(row.final()) << ',' << 
            setw(2) << begin << ',' << 
            setw(2) << addAccept(row, accept) << "},\n";
}

