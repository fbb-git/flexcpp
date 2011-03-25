#include "charclass.ih"

spSemVal CharClass::difference(SemVal const &lhs, SemVal const &rhs)
{
    set<char> lset = downCast<CharClass>(lhs).set();
    set<char> rset = downCast<CharClass>(rhs).set();

    set<char> dest;
    set_difference(lset.begin(), lset.end(), rset.begin(), rset.end(),
                    inserter(dest, dest.begin()));

    spSemVal ret(new CharClass(dest));

    return ret;
}
