#include "parser.ih"

void Parser::modePattern()
{
    d_scanner.reset(Scanner::pattern);
    s_lastMsg.clear();
    d_parentheses = 0;
    d_accept = 0;
    d_patternTokenCount = 0;
}