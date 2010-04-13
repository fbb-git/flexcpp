#include "ranges.ih"

void Ranges::add(Type type, string const &str)
{
    string tmp;

    if (type == NOT_ORDERED)
    {
        tmp = str;
        sort(tmp.begin(), tmp.end());
    }
    string const &strRef =  type == NOT_ORDERED ? tmp : str;

    size_t *next = new size_t[d_size];
    
        // initialize next values with d_ranges
    copy(d_ranges, d_ranges + d_size, next);

        // increment next counts for chars in str
    for_each(strRef.begin(), strRef.end(), FnWrap::unary(incIf, next));

    updateRanges(strRef, next);
}
