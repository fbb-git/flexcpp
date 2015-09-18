#include "dfa.hh"

// called from keepUniqueRows

void DFA::inspectRows(vector<size_t> &unique)
{
    // visit all d_row rows, for each row see if that row has already been
    // defined. In that case an earlier row equals the current row. 
    // If the row hasn't been defined before, store its index, otherwise
    // store the index of the earlier row.
    // Equal rows means: same transition vector

    for
    (
        size_t rowIdx = 0, end = d_row.size(), nextRow = 0; 
            rowIdx != end;
                ++rowIdx
    )
    {
        size_t useRow = available(d_row[rowIdx]);

        unique.push_back(
            useRow == rowIdx ?       // unique row
                nextRow++                   // then store it as the next row
            :
                unique[useRow]              // or use the existing row's idx
        );
    }
}
