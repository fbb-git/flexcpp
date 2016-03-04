#include "dfa.ih"

ostream &operator<<(ostream &out, DFA const &dfa)
{
    if (dfa.d_nUsedRanges == 0)
    {
        out << "    No transitions\n"
                "\n";
        return out;
    }

    size_t nCols = dfa.d_nUsedRanges + 2;

    TableLines support;
    support << 0;

    for (size_t idx = 0; idx !=  nCols - 2; ++idx)   // set separator widths
        support << 2;

    support << 3 << 3 << 2;                         // F column stands out
                                                    // more clearly

    support << TableSupport::HLine(1, 1, nCols + 1);// partial 2nd line 

    Table table(support, nCols, Table::ROWWISE);
    table << Align(nCols - 2, std::left) << Align(nCols - 1, std::left);


    table << "   ";                                // char-ranges display
    for (size_t idx = 0, end = dfa.d_ranges->nRanges(); idx != end; ++idx)
    {
        if (dfa.d_usedRanges[idx])
            table << idx;
    }
    table << 'F';
                                                // display rows of the table
    for 
    (
        size_t idx = 0, end = dfa.d_row.size(), next = 0;
            idx != end; 
                ++idx)
    {
        table << next << dfa.d_row[idx];
        ++next;
    }
    out << table << '\n';

    return out;
}
        
