#include "options.ih"

Options::Options(Arg const &arg)
:
    d_arg(arg),
    d_infile(arg[0]),
    d_interactive(false),
    d_lines(not arg.option(0, "no-lines")),
    d_print(false),
    d_debug(false),
    d_matchedRules(arg.option('R')),
    d_verbose(arg.option('V')),
    d_maxDepth(10)
{
    if (arg.option(0, "regex-calls"))
        s_regexCall = show;
}
