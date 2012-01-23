#include "parser.ih"

spSemUnion Parser::eofPattern()
{
    spSemUnion ret(PatternVal::eof(d_states));

    return ret;
}
