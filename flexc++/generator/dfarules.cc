#include "generator.ih"

void Generator::dfaRules(DFARow const &row, ostream &out)
{
    auto final = row.final();

    out << 
        setw(3) << 
            (final.first != max<size_t>() ? 
                static_cast<int>(final.first) : -1) << ',' << 
        setw(3) << 
            (final.second != max<size_t>() ? 
                static_cast<int>(final.second) : -1);
}







