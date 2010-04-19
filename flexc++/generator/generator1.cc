#include "generator.ih"

Generator::Generator(size_t nRules, Ranges const &ranges)
:
    d_ranges(ranges),
    d_nRules(nRules)
{
    Msg::open(d_out, "STATICS");
}
