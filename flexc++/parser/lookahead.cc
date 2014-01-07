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

    Pattern ret;
    if (right.canBeEmpty(d_states))
        ret = left;    
    else
    {
        ret = Pattern(d_states, left, right,  d_lopStartCondition);
        d_lopStartCondition += 2;
    }

    return ret;
}


