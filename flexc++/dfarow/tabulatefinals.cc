#include "dfarow.hh"

void DFARow::tabulateFinals(Table &table) const
{
    size_t first = d_finalRule.first;
    size_t second = d_finalRule.second;

    ostringstream out;

    if (first != max<size_t>())
    {
        out << d_finalRule.first;
        if (second != max<size_t>())
            out << ',';
    }

    if (second != max<size_t>())
        out << second;

    table << out.str();
}








