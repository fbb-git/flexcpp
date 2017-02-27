#include "generator.ih"

bool Generator::debugTest() const
{
    return  d_debug || (d_field == "R" && d_options('R'));
}
