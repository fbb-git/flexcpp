#include "charrange.ih"

//#include <iostream>
//#include <algorithm>
//#include <iterator>

set<char> CharRange::negate(set<char> const &cSet)
{
    AllChars begin(0);
    AllChars end(UCHAR_MAX);

//std::cerr << "IN-SET: ";
//copy(cSet.begin(), cSet.end(), ostream_iterator<int>(std::cerr, ", "));
//std::cerr << "\n";

    set<char> ret;

    set_difference(begin, end, cSet.begin(), cSet.end(), 
                                                inserter(ret, ret.end()));

//std::cerr << "NEGATED-SET: ";
//copy(ret.begin(), ret.end(), ostream_iterator<int>(std::cerr, ", "));
//std::cerr << "\n";

    return ret;
}
