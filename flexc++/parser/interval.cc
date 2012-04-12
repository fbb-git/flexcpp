#include "parser.ih"

Pattern Parser::interval(Pattern const &regex, Interval const &interval)
{
    Options::regexCall("interval");

    d_scanner.multiAsChar();
    return Pattern::interval(d_states, const_cast<Pattern &>(regex), 
                                       interval);
}
    
