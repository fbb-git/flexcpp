#include "parser.ih"

void Parser::warnForSpecialChars() const
{
    int ch = d_scanner.match()[0];

    if (ch == '$' || ch == '^')
        wmsg << '\'' << static_cast<char>(ch) << 
            "' inside a pattern looses its special meaning" << endl;
}
