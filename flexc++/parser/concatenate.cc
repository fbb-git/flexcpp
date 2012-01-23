#include "parser.ih"

spSemUnion Parser::concatenate(spSemUnion &lhs, spSemUnion &rhs)
{

    spSemUnion ret(
                PatternVal::concatenate(
                    d_states,
                    lhs->value<SemUnion::PATTERNVAL>(), 
                    rhs->value<SemUnion::PATTERNVAL>()
                )
       );

    return ret;
}


