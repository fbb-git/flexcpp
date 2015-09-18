#include "dfarow.hh"

void DFARow::tabulate(Table &table) const
{
    tabulateTransitions(table);
    tabulateFinals(table);
}








