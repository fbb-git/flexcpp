#include "dfa.ih"

#include <iostream>
#include <bobcat/table>
#include <bobcat/tablesupport>

ostream &operator<<(ostream & out, DFA const &dfa)
{
    TableSupport support;
    support << 0 << 2;
    for (size_t idx = 0; idx++ != dfa.d_nRanges; )
        support << 2;

    Table table(support, dfa.d_nRanges + 1, Table::ROWWISE);

    table << " ";
    for (size_t idx = 0; idx++ != dfa.d_nRanges; )
        table << idx;

    for (size_t idx = 0, end = dfa.d_row.size(); idx != end; ++idx)
    {
        table << idx;
        dfa.d_row[idx].tabulate(table);
    }

        
    out << table << "--------" <<'\n';

    return out;
}
        
