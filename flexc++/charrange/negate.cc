#include "charrange.ih"

set<char> CharRange::negate(set<char> const &cSet)
{
    AllChars begin(0);
    AllChars end(UCHAR_MAX);

    set<char> ret;
    set_difference(begin, end, cSet.begin(), cSet.end(), 
                                                inserter(ret, ret.end()));
    return ret;
}
