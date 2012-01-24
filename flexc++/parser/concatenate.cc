#include "parser.ih"

spSemUnion Parser::concatenate(spSemUnion &lhs, spSemUnion &rhs)
{

    spSemUnion ret(
                PatternVal::concatenate(
                    d_states,
                    lhs->value<PATTERNVAL>(), 
                    rhs->value<PATTERNVAL>()
                )
       );

    return ret;
}


