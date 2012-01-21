#include "parser.ih"

void Parser::warnForSpecialChars() const
{
    int ch = d_scanner.matched()[0];

    if (ch == '$' || ch == '^')
        wmsg << '\'' << static_cast<char>(ch) << 
            "' inside a pattern loses its special meaning" << endl;
}
