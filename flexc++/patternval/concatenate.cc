#include "patternval.ih"

// States:
//          B1 -> E1  and B2 -> E2
// becomes:
//          B1 -> E1 -> E2, where B2 is assigned to E1
// B2 is returned to the State's free store.

spSemVal PatternVal::concatenate(States &states, SemVal &left, SemVal &right)
{
    PatternVal &lhs = downCast<PatternVal>(left);
    PatternVal &rhs = downCast<PatternVal>(right);

    states[lhs.end()] = states[rhs.begin()];
    states.collect(rhs.begin());

    spSemVal ret(new PatternVal( {lhs.begin(), rhs.end()} ));

    return ret;
}



