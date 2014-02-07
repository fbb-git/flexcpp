#include "charclass.ih"

CharClass CharClass::difference(CharClass &lhs, CharClass &rhs)
{
    std::set<char> const &lset = lhs.set();
    std::set<char> const &rset = rhs.set();

    std::set<char> dest;

    set_difference(lset.begin(), lset.end(), rset.begin(), rset.end(),
                   inserter(dest, dest.begin()));

    CharClass ret(dest);
    return ret;
}
