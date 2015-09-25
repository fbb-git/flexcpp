#include "parser.ih"

void Parser::print()
{
    if (d_printTokens && d_token__ != s_ignoreToken)
    {
        std::cout << "Token: " << symbol__(d_token__);

        if (isprint(d_token__) || d_token__ > 0xff)
            std::cout << ", text: `" << d_matched << "'\n";
        else
            std::cout << '\n';
    }
}
