#include "parser.ih"

void Parser::modePattern()
{
    d_scanner.reset(StartCondition__::pattern);
    s_lastMsg.clear();
    d_parentheses = 0;
    d_usesLOP = false;
    d_BOLpattern = false;
    d_patternTokenCount = 0;
}
