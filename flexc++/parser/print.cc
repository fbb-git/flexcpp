#include "parser.ih"

void Parser::print()
{
    if (d_printTokens && token__() != s_ignoreToken)
    {
        std::cout << "Token: " << symbol__(token__());

        if (isprint(token__()) || token__() > 0xff)
            std::cout << ", text: `" << d_matched << "'\n";
        else
            std::cout << '\n';
    }
}
