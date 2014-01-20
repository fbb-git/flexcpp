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

    Pattern ret;
    if (right.canBeEmpty(d_states))
        ret = left;    
    else if (right.fixedLength())            // fixed tail lop rule
    {
        d_rules.setFixedTailLOPrules();
        ret = Pattern(d_states, right.length(), left, right);
    }
    else
    {
        d_rules.setVariableTailLOPrules();
        ret = Pattern(d_states, left, right,  d_nLOPstartConditions);
        d_nLOPstartConditions += 2;
        d_scanner.needCatchAll();
    }

    return ret;
}



