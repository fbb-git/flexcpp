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

    PatternVal &lval = SemVal::downCast<PatternVal>(left);

    d_accept = lval.end();
    d_states[d_accept].setAccept(State::NON_INHERITING);

    spSemVal ret = PatternVal::concatenate(d_states, left, right);

    return ret;
}
