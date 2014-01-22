#include "generator.ih"

void Generator::dfaFinalRules(DFARow const &row, ostream &out)
{
    auto final = row.final();

    out << setw(3) << 
        (final.first != numeric_limits<size_t>::max() ? 
                static_cast<int>(final.first) : -1) <<
        ',' << setw(3) << 
        (final.second != numeric_limits<size_t>::max() ? 
                static_cast<int>(final.second) : -1);
}







