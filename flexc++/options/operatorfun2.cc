#include "options.hh"

bool Options::operator()(char const *opt) const
{
    return d_arg.option(0, opt);
}
