#include "charclass.ih"

spSemVal CharClass::difference(SemVal const &lhs, SemVal const &rhs)
{
    set<char> const &lset = downCast<CharClass>(lhs).d_set;
    set<char> const &rset = downCast<CharClass>(rhs).d_set;

    CharClass *data = new CharClass;
    spSemVal ret(data);

    set_difference(lset.begin(), lset.end(), rset.begin(), rset.end(),
                    inserter(data->d_set, (data->d_set).begin()));

    return ret;
}
