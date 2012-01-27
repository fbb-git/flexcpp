#include "parser.ih"

void Parser::nlReset()
{
    s_lastMsg.clear();
    d_parentheses = 0;
    d_usesLOP = false;
    d_boln = false;
    d_warnCarets = false;
    d_warnDollars = false;
    d_tokenCount = 0;
}
