#include "generator.ih"

void Generator::dfaRow(DFARow const &row, ostream &out, 
                        PVector &accept, PVector &final)
{
    out << "        {";

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

    size_t beginFinal =  final.size();
    size_t beginAccept =  accept.size();

    out << setw(2) << beginfinal << ',' << 
            setw(2) << addFinal(row, final) << ", " <<
            setw(2) << beginAccept << ',' << 
            setw(2) << addAccept(row, accept) << "},\n";
}
