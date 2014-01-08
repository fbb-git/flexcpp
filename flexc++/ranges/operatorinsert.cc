#include "ranges.ih"

ostream &operator<<(ostream &out, Ranges const &rangesObj)
{
    out << "Nsubsets: " << rangesObj.d_nRanges << '\n';

    size_t *ranges = rangesObj.d_alphabet;
    size_t *begin = ranges;
    size_t *end = ranges + rangesObj.d_alphabetSize;
    size_t range = 0;

    while (begin != end)
    {
        size_t *last = find_if(begin, end, 
                                   bind2nd(not_equal_to<size_t>(), *begin));

        out << setw(2) << range++ << ": ";
        Ranges::outChar(out, begin - ranges);

        if (begin  != last - 1)
        {
            out << " - ";
            Ranges::outChar(out, last - ranges - 1);
        }

        out << '\n';
        
        begin = last;
    }

    if (size_t bol = rangesObj.rangeOfBOL())
        out << "BOL: " << bol << '\n';

    if (size_t eof = rangesObj.rangeOfEOF())
        out << "EOF: " << eof << '\n';

    return out;
}

