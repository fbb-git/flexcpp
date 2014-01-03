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
        d_usesLOP = true;
        d_lhs.duplicate(left);          // duplicate the lhs, so it can be
                                        // used to perform the lop-match
        d_rhs = right;                  // the rhs can be kept as-is, as it
                                        // simply represents the lop's rhs.
        ret = Pattern::concatenate(d_states, left, right);
    }

    return ret;
}








