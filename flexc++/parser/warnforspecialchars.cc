#include "parser.ih"

void Parser::warnForSpecialChars() const
{
    int ch = d_scanner.match()[0];

    if (ch == '$' || ch == '^')
        lineMsg() << '\'' << static_cast<char>(ch) << 
            "' inside a pattern looses its special meaning" << warning;
}
