#include "parser.ih"

spSemUnion Parser::lookahead(spSemUnion &left, spSemUnion &right)
{
    Options::regexCall("lookahead");

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

    Pattern &lval = left->value<PATTERN>();
    setFlags(lval.begin(), State::PRE);

    Pattern &rval = right->value<PATTERN>();
    setFlags(rval.begin(), State::POST);

    d_states[rval.begin()].setFlag(State::ACCEPT);

    return concatenate(left, right);
}








