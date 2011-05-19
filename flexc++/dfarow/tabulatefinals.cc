#include "dfarow.ih"

void DFARow::tabulateFinals(Table &table) const
{
    size_t first = d_finalRule.first;
    size_t second = d_finalRule.second;

    ostringstream out;

    if (first != UINT_MAX)
    {
        out << d_finalRule.first;
        if (second != UINT_MAX)
            out << ',';
    }
    if (second != UINT_MAX)
        out << second;

    table << out.str();
}








