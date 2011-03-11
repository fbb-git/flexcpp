#include "generator.ih"

Generator::Generator(Rules const &rules, Ranges const &ranges, 
                    DFAs const & dfas)
:
    d_options(Options::instance()),
    d_arg(Arg::instance()),
    d_rules(rules),
    d_ranges(ranges),
    d_dfas(dfas),
    d_dfaIndices(1, 0)
{
    d_options.setAccessorVariables();
}
