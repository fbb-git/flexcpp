#include "options.ih"

bool Options::operator()(int opt) const
{   
    return d_arg.option(opt);
}
