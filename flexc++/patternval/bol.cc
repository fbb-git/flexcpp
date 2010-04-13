#include "patternval.ih"

spSemVal PatternVal::bol(States &states, SemVal &pattern)
{
    spSemVal bolVal = plain(states, State::BOL);
    
    spSemVal ret = concatenate(states, *plain(states, State::BOL), pattern);
    return ret;
}



