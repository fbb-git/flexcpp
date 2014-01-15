#include "parser.ih"

#include "../states/states.h" //TMP

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

    Pattern ret;
    if (right.canBeEmpty(d_states))
        ret = left;    
    else
    {
cerr << d_states << '\n';

        ret = Pattern(d_states, left, right,  d_lopStartCondition);
        d_lopStartCondition += 2;

cerr << d_states << '\n';
    }

    d_scanner.needCatchAll();

    return ret;
}



