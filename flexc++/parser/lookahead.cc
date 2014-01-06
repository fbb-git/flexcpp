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

    
    Pattern ret = right.canBeEmpty(d_states) ?
                    left
                :
                    Pattern(left, right);

    return ret;
}


