#include "usage.ih"

void Usage::add(Type type, string const &str)
{
    string tmp;

    if (type == NOT_ORDERED)
    {
        tmp = str;
        sort(tmp.begin(), tmp.end());
    }
    string const &strRef =  type == NOT_ORDERED ? tmp : str;

    size_t *next = new size_t[d_size];
    
        // initialize next values with d_usage
    copy(d_usage, d_usage + d_size, next);

        // increment next counts for chars in str
    for_each(strRef.begin(), strRef.end(), FnWrap::unary(incIf, next));

    updateUsage(strRef, next);
}
