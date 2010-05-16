#include "dfa.ih"

// called from keepUniqueRows

void DFA::inspectRows(vector<size_t> &unique)
{
    size_t end = d_row.size();
    for
    (
        size_t rowIdx = 0, nextRow = 0; 
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
