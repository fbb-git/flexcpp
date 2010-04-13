#include "parser.ih"

spSemVal Parser::lookahead(SemVal &left, SemVal &right)
{
    d_doError = false;

    if (d_accept != 0)
    {
        lineMsg() << "multiple trailing contexts ('/', '$') not supported" <<
                                                                        err;
        ERROR();
    }

    if (d_parentheses)
    {
        lineMsg() << 
            "parenthesized trailing contexts ('/', '$') not supported" << err;
        ERROR();
    }

    d_doError = true;

    PatternVal &pval = SemVal::downCast<PatternVal>(right);
    d_accept = pval.begin();
    d_inheriting =  pval.end() != 0;

    spSemVal ret = PatternVal::concatenate(d_states, left, right);

    return ret;
}
