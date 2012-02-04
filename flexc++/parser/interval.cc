#include "parser.ih"

spSemUnion Parser::interval(spSemUnion &regex, spSemUnion const &interval)
{
    d_scanner.multiAsChar();
    return Pattern::interval(d_states, 
                            regex->value<PATTERN>(),
                            interval->value<INTERVAL>());
}
    
