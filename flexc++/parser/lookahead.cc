#include "parser.ih"

Pattern Parser::lookahead(Pattern const &left, Pattern const &right)
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

    setFlags(left.begin(), State::PRE);
    setFlags(right.begin(), State::POST);

    d_states[right.begin()].setFlag(State::ACCEPT);

    return Pattern::concatenate(d_states, left, right);
}








