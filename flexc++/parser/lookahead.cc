#include "parser.ih"

spSemVal Parser::lookahead(SemVal &left, SemVal &right)
{
    d_doError = false;

    if (d_accept != 0)
    {
        emsg << "multiple trailing contexts ('/', '$') not supported" << endl;
        ERROR();
    }

    if (d_parentheses)
    {
        emsg << "parenthesized trailing contexts ('/', '$') not supported" << 
                                                                        endl;
        ERROR();
    }

    d_doError = true;

    PatternVal &lval = SemVal::downCast<PatternVal>(left);

    d_accept = lval.end();
    d_states[d_accept].setAccept(0);

    spSemVal ret = PatternVal::concatenate(d_states, left, right);

    return ret;
}








