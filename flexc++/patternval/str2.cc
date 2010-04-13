#include "patternval.ih"

spSemVal PatternVal::str(States &states, State::Type type, 
                         SemVal const &charClass)
{
    States::Pair pair = states.next2();

    states[pair.first] = State::factory(type, 
                                        downCast<CharClass>(charClass).str(), 
                                        pair.second);
    
    spSemVal ret(new PatternVal(pair));
    return ret;
}
