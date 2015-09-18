#include "options.hh"

bool Options::operator()(int opt) const
{   
    return d_arg.option(opt);
}
