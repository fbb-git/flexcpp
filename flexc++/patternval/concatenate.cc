#include "patternval.ih"

// States:
//          B1 -> E1  and B2 -> E2
// becomes:
//          B1 -> E1 -e-> B2 -> E2

spSemVal PatternVal::concatenate(States &states, SemVal &left, SemVal &right)
{
    PatternVal &lhs = downCast<PatternVal>(left);
    PatternVal &rhs = downCast<PatternVal>(right);

    states[lhs.end()].data().set(rhs.begin());
    states[lhs.end()].setType(State::EMPTY);

    spSemVal ret(new PatternVal( {lhs.begin(), rhs.end()} ));

    return ret;
}



