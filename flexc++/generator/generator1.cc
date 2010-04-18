#include "generator.ih"

Generator::Generator(Ranges const &ranges)
:
    d_ranges(ranges),
    d_acceptSize(0)
{
    Msg::open(d_out, "STATICS");
}
