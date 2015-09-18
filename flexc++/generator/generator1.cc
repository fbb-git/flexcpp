#include "generator.hh"

Generator::Generator(Rules const &rules, Ranges const &ranges, 
                    DFAs const & dfas)
:
    d_options(Options::instance()),
    d_rules(rules),
    d_ranges(ranges),
    d_dfas(dfas),
    d_lopUsed(rules.hasLOPrules()),
    d_dfaIndices(1, 0)
{
    d_baseclassScope = d_options.className() + "Base::";
    d_lineDirectives = d_options.lines();
    d_debug          = d_options.debug();
}
