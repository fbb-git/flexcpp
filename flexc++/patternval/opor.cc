#include "patternval.ih"

spSemVal PatternVal::opOr(States &states, SemVal &left, SemVal &right)
{
    PatternVal &lhs = downCast<PatternVal>(left);
    PatternVal &rhs = downCast<PatternVal>(right);

    States::Pair pair = states.next2();
    states[pair.first] = State::factory(State::EMPTY, lhs.begin(), 
                                                      rhs.begin());

    states[lhs.end()] = State::factory(State::EMPTY, pair.second);
    states[rhs.end()] = State::factory(State::EMPTY, pair.second);

    spSemVal ret(new PatternVal(pair));

    return ret;
}



