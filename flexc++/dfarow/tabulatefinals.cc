#include "dfarow.ih"

void DFARow::tabulateFinals(Table &table) const
{
    size_t first = d_finalRule.first;
    size_t second = d_finalRule.second;

    ostringstream out;

    if (first != numeric_limits<size_t>::max())
    {
        out << d_finalRule.first;
        if (second != numeric_limits<size_t>::max())
            out << ',';
    }
    if (second != numeric_limits<size_t>::max())
        out << second;

    table << out.str();
}








