#include "options.ih"

Options::Options()
:
    d_arg(Arg::instance()),
    d_infile(d_arg[0]),
    d_lines(not d_arg.option(0, "no-lines")),
    d_matchedRules(d_arg.option('R')),
    d_verbose(d_arg.option('V')),
    d_caseSensitive(not d_arg.option(0, "case-insensitive"))
{
    if (d_arg.option(0, "regex-calls"))
        s_regexCall = show;
}
