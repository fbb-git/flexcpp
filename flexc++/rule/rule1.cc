#include "rule.ih"

Rule::Rule(States const &states, bool bol, Pair fstfin, 
           Block const &block, std::string const &source, size_t lineNr)
:
    d_start(fstfin.first),                  // 1st state of this rule
    d_final(fstfin.second),                 // final state of this rule
    d_block(block),
    d_bol(bol),
    d_viable(false),
    d_source(source),
    d_lineNr(lineNr)
{}
