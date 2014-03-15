#include "rule.ih"

Rule::Rule(States &states, bool bol, Pattern const &pattern,
           Block const &block, RuleType type)
:
    d_pattern(pattern),
    d_block(block),
    d_bol(bol),
    d_type(type)
{}

