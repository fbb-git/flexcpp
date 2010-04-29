#include "generator.ih"

void Generator::dfaRow(DFARow const &row, ostream &out, 
                        PVector &accept, vector<size_t> &final)
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

//    size_t beginFinal =  final.size();

    out << "TO COMPLETE: Generator::dfaRow\n";

//    out << setw(2) << beginFinal << ',' << 
//            setw(2) << addFinal(row, final) << ", " <<
//            setw(2) << row.acceptRule() << ", '" << 
//            row.ruleAcceptType() << "'},\n";
}

