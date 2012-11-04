#include "options.ih"

Options::Options(Arg const &arg)
:
    d_arg(arg),
    d_infile(arg[0]),
    d_lines(not arg.option(0, "no-lines")),
    d_matchedRules(arg.option('R')),
    d_verbose(arg.option('V')),
    d_caseSensitive(not arg.option(0, "case-insensitive"))
{
    if (arg.option(0, "regex-calls"))
        s_regexCall = show;
}
