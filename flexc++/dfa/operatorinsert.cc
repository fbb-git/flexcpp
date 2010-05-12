#include "dfa.ih"

ostream &operator<<(ostream &out, DFA const &dfa)
{
    size_t nCols = dfa.d_ranges->nUsed() + 3;

    TableLines support;
    support << 0;
    for (size_t idx = 0; idx != nCols - 3; ++idx)   // set separator widths
        support << 2;
    support << 3 << 3 << 2;                         // F column stands out
                                                    // more clearly

    support << TableSupport::HLine(1, 1, nCols + 1);// partial 2nd line 

    Table table(support, nCols, Table::ROWWISE);
    table << Align(nCols - 2, std::left);


    table << "   ";                                // char-ranges display
    for (size_t idx = 0, end = dfa.d_ranges->size(); idx++ != end; )
    {
        if (dfa.d_ranges->used(idx))
            table << idx;
    }
    table << 'F' << 'A';
                                                // display rows of the table
    for (size_t idx = 0, end = dfa.d_row.size(); idx != end; ++idx)
        table << idx << dfa.d_row[idx];

    out << table << '\n';

    return out;
}
        
