#include "parser.ih"

Parser::Parser(Rules &rules, States &states)
:
    d_arg(Arg::instance()),
    d_scanner(d_arg[0]),
    d_options(Options::instance()),
    d_printTokens(d_arg.option('t')),
    d_parentheses(0),
    d_accept(0),
    d_inheriting(false),
    d_patternTokenCount(0),
    d_doError(true),
    d_rules(rules),
    d_states(states)
{
    s_ignoreToken = d_token__;
    setDebug(d_arg.option('d'));
}
