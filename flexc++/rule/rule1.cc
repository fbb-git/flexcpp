#include "rule.ih"

Rule::Rule(States const &states, bool bol, Pair fstfin, 
// size_t accept, 
           Block const &block, std::string const &source, size_t lineNr)
:
    d_start(fstfin.first),                  // 1st state of this rule
    d_final(fstfin.second),                 // final state of this rule
    d_block(block),
    d_LAdone(false),
    d_bol(bol),
//states[fstfin.first].type() == State::BOL),

    d_viable(false),
    d_source(source),
    d_lineNr(lineNr)
{
//    if (accept != 0)                        // this rule uses the LA operator, 
//    {                                       // so it has an accept state
//
//        setStates(d_preAstates, states, fstfin.first, accept); 
//        setStates(d_postAstates, states, accept, fstfin.second);
//
//        d_postAstates.push_back(fstfin.second); // the final state is also
//                                                // of the post-A states
//
//    }
}
