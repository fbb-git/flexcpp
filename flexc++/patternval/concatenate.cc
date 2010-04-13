#include "patternval.ih"

// States:
//          B1 -> E1  and B2 -> E2
// becomes:
//          B1 -> B2 -> E2
//  E1 is no longer used and is collected by States

spSemVal PatternVal::concatenate(States &states, SemVal &left, SemVal &right)
{
    PatternVal &lhs = downCast<PatternVal>(left);
    PatternVal &rhs = downCast<PatternVal>(right);

    states.collect(lhs.end());
    states[lhs.begin()].data().set(rhs.begin());

    spSemVal ret(new PatternVal( {lhs.begin(), rhs.end()} ));

    return ret;
}



