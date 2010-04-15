#include "dfa.ih"

#include <bobcat/table>

ostream &operator<<(ostream & out, DFA const &dfa)
{
    size_t nCols = dfa.d_nRanges + 3;

    DSupport support;
    support << 0;
    for (size_t idx = 0; idx != nCols; ++idx)
        support << 2;
    support << TableSupport::HLine(1, 1, nCols + 1);

    Table table(support, nCols, Table::ROWWISE);

    table << " ";
    for (size_t idx = 0; idx++ != dfa.d_nRanges; )
        table << idx;
    table << 'F' << 'A';

    for (size_t idx = 0, end = dfa.d_row.size(); idx != end; ++idx)
    {
        table << idx;
        dfa.d_row[idx].tabulate(table);
    }

        
    out << table << '\n';

    return out;
}
        
