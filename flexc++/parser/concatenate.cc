#include "parser.ih"

spSemUnion Parser::concatenate(spSemUnion &lhs, spSemUnion &rhs)
{

    spSemUnion ret(
                Pattern::concatenate(
                    d_states,
                    lhs->value<PATTERN>(), 
                    rhs->value<PATTERN>()
                )
       );

    return ret;
}


