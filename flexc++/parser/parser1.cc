#include "parser.ih"

Parser::Parser(Rules &rules, States &states)
:
    d_options(Options::instance()),
    d_scanner(d_options.infile()),
    d_matched(d_scanner.matched()),
    d_block(0, ""),
    d_printTokens(d_options('T')),
    d_rules(rules),
    d_states(states)
{
    s_ignoreToken = d_token__;      // set by ParserBase to _UNDETERMINED
    setDebug(d_options.debug());
}

