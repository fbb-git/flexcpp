#include "parser.ih"

spSemVal Parser::eofPattern()
{
    d_doError = false;

    if (d_patternTokenCount != 1)
    {
        emsg << "<<EOF>> can only be used at a pattern's begin" << endl;
        ERROR();
    }

    if (d_parentheses)
    {
        emsg << "<<EOF>> cannot be used within parentheses" << endl;
        ERROR();
    }

    d_doError = true;
    spSemVal ret = PatternVal::eof(d_states);

    return ret;
}
