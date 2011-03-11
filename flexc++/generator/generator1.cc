#include "generator.ih"

Generator::Generator(Rules const &rules, Ranges const &ranges)
:
    d_ranges(ranges),
    d_options(Options::instance()),
    d_arg(Arg::instance()),
    d_rules(rules)
{
    Errno::open(d_out, "STATICS");
    d_options.setAccessorVariables();
}
