#include "generator.ih"

Generator::Generator(Rules const &rules, Ranges const &ranges, 
                    DFAs const & dfas)
:
    d_options(Options::instance()),
    d_arg(Arg::instance()),
    d_rules(rules),
    d_ranges(ranges),
    d_dfas(dfas),
    d_useBOL(d_ranges.rangeOfEOF() + 3 != dfaCols()),
    d_dfaIndices(1, 0)
{
    d_options.setAccessorVariables();
    d_baseclassScope = d_options.className() + "Base::";
    d_lineDirectives = d_options.lines();
    d_debug          = d_options.debug();
    d_debugStep      = d_options.beginStep() != d_options.endStep();
}
