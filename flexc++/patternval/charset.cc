#include "patternval.ih"

spSemVal PatternVal::charSet(States &states, SemVal const &charClass)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(State::CHARSET, 
                                        downCast<CharClass>(charClass).str(), 
                                        pair.second);
    
    spSemVal ret(new PatternVal(pair));
    return ret;
}
