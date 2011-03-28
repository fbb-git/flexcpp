#include "charclass.ih"

spSemVal CharClass::difference(SemVal const &lhs, SemVal const &rhs)
{
    spSemVal ret;
    std::set<char> lset = downCast<CharClass>(lhs).set();
    std::set<char> rset = downCast<CharClass>(rhs).set();

    std::set<char> dest;
    set_difference(lset.begin(), lset.end(), rset.begin(), rset.end(),
                    inserter(dest, dest.begin()));

    ret = spSemVal(new CharClass(dest));
    return ret;
}
