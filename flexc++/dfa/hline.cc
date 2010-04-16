#include "dfa.ih"

void DSupport::hline(size_t row) const
{
    if (row == 0 or row == nRows())
        out() << setfill('-') << setw(width()) << "-" << setfill(' ') << '\n';
    else if (row == 1)
    {
        for_each(begin(1), end(), FnWrap::unary(outLine, out()));
        out() << '\n';
    }
}
