#include "parser.ih"

void Parser::print()
{
    if (d_printTokens && token_() != s_ignoreToken)
    {
        std::cout << "Token: " << symbol_(token_());

        if (isprint(token_()) || token_() > 0xff)
            std::cout << ", text: `" << d_matched << "'\n";
        else
            std::cout << '\n';
    }
}
