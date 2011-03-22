#include "options.ih"

Options::Options()
:
    d_interactive(false),
    d_lines(true),
    d_beginStep(~0U),
    d_endStep(~0U),
    d_debugAll(false)
{}
