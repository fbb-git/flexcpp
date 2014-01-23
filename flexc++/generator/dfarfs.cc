#include "generator.ih"

void Generator::dfaRFs(DFARow const &row, ostream &out, 
                        vector<RuleFlag> &rf)
{
    auto final = row.final();

    int nonBolRule = -1;
    int bolRule = -1;

    if (final.first != max<size_t>())
        nonBolRule = final.first;

    if (final.second != max<size_t>())
        bolRule = final.second;

    out << setw(3) << nonBolRule << ',' << setw(3) << bolRule;
}







