#include "generator.ih"

Generator::Generator(Ranges const &ranges)
:
    d_ranges(ranges)
{
    Msg::open(d_out, "STATICS");
}
