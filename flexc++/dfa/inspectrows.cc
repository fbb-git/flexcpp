#include "dfa.ih"

// called from keepUniqueRows

void DFA::inspectRows(vector<size_t> &unique)
{
    // visit all d_row rows, for each row see if it's already available
    // if not then use the row by storing its new index, otherwise
    // store the index of an earlier row.

    for
    (
        size_t rowIdx = 0, end = d_row.size(), nextRow = 0; 
            rowIdx != end;
                ++rowIdx
    )
    {
        size_t useRow = available(d_row[rowIdx]);
        unique.push_back(
            useRow == unique.size() ?     // unique row
                nextRow++                   // then store it as the next row
            :
                unique[useRow]            // or use the existing row
        );
    }
}
