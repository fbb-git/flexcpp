#include "dfarow.hh"

Table &operator<<(Table &table, DFARow const &row)
{
    row.tabulate(table);
    return table;
}
