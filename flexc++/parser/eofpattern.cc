#include "parser.ih"

spSemUnion Parser::eofPattern()
{
    spSemUnion ret(Pattern::eof(d_states));

    return ret;
}
