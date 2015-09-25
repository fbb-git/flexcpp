#include "charclass.ih"

CharClass CharClass::unite(CharClass &lhs, CharClass &rhs)
{
    std::set<char> const &lset = lhs.set();
    std::set<char> const &rset = rhs.set();

    CharClass ret;
    ret.d_state = FINAL;

    set_union(lset.begin(), lset.end(), rset.begin(), rset.end(),
              back_inserter(ret.d_str));

    return ret;
}
