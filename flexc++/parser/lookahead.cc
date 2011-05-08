#include "parser.ih"

spSemVal Parser::lookahead(SemVal &left, SemVal &right)
{
    d_doError = false;

    if (d_usesLOP)
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
    d_usesLOP = true;

    PatternVal &lval = SemVal::downCast<PatternVal>(left);
    setFlags(lval.begin(), State::PRE);

    PatternVal &rval = SemVal::downCast<PatternVal>(right);
    setFlags(rval.begin(), State::POST);

    d_states[rval.begin()].setFlag(State::ACCEPT);

    spSemVal ret = PatternVal::concatenate(d_states, left, right);

    return ret;
}








