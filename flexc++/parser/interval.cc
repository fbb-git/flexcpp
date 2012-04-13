#include "parser.ih"

Pattern Parser::interval(Pattern &regex, Interval const &interval)
{
    Options::regexCall("interval");

    d_scanner.multiAsChar();
    return Pattern::interval(d_states, regex, interval);
}
    
