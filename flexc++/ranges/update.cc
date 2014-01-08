#include "ranges.ih"

// update receives in next the new count of character occurrences.
// after correcting for collisions ...

void Ranges::update(string const &str, size_t const *next)
{
        // if pre- post- character range collisions
        // add next to ranges, otherwise copy next to ranges
        //    
    if (collision(str, next))       
        transform(d_alphabet, d_alphabet + d_alphabetSize, next, d_alphabet, plus<size_t>());
    else
        copy(next, next + d_alphabetSize, d_alphabet);

        // Determine the numbers used in the ranges, reduce the actual
        // d_range vaues by their indices in rangeNrs
    vector<size_t> rangeNrs;

    for_each(
        d_alphabet, d_alphabet + d_alphabetSize, 
        [&](size_t &count)
        {
            countRanges(count, rangeNrs);
        }
    );

    subsetCount();                      // count the subsets
}



