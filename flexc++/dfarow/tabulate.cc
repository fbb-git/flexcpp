#include "dfarow.ih"

void DFARow::tabulate(Table &table) const
{
    tabulateTransitions(table);
    tabulateFinals(table);
}








