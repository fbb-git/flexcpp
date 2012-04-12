#include "parser.ih"

Parser::Parser(Rules &rules, States &states)
:
    d_arg(Arg::instance()),

    d_scanner(d_arg[0]),
    d_matched(d_scanner.matched()),
    d_block(0, ""),

    d_options(Options::instance()),

    d_boln(0),
    d_doError(true),
    d_printTokens(d_arg.option('T')),
    d_usesLOP(false),
    d_warnCarets(false),
    d_warnDollars(false),
    d_parentheses(0),
    d_tokenCount(0),

    d_rules(rules),
    d_states(states)
{
    s_ignoreToken = d_token__;      // set by ParserBase to _UNDETERMINED
    setDebug(d_arg.option('d'));
}

