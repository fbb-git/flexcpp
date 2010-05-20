#include "generator.ih"

void Generator::dfaRow(DFARow const &row, ostream &out, 
                        PVector &accept, vector<size_t> &final)
{
    out << "        {";

    dfaTransitions(row, out);

//    size_t beginFinal =  final.size();

    out << "TO COMPLETE: Generator::dfaRow\n";

//    out << setw(2) << beginFinal << ',' << 
//            setw(2) << addFinal(row, final) << ", " <<
//            setw(2) << row.acceptRule() << ", '" << 
//            row.ruleAcceptType() << "'},\n";
}

