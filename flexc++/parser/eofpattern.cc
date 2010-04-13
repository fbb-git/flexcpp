#include "parser.ih"

spSemVal Parser::eofPattern()
{
    d_doError = false;

    if (d_patternTokenCount != 1)
    {
        lineMsg() << "<<EOF>> can only be used at a pattern's begin" << err;
        ERROR();
    }

    if (d_parentheses)
    {
        lineMsg() << "<<EOF>> cannot be used within parentheses" << err;
        ERROR();
    }

    d_doError = true;
    spSemVal ret = PatternVal::eof(d_states);

    return ret;
}
