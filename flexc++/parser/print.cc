#include "parser.ih"

void Parser::print()
{
    if (d_printTokens && d_token__ != s_ignoreToken)
    {
        
        std::cout << "Token: " << symbol__(d_token__);

        if (d_token__ == BLOCK)
        {
            string const &block = d_scanner.block().str();
            size_t len = block.length();

            if (len <= 40)
                std::cout << ", text: `" << block << "'\n";
            else
                std::cout << ", text: `" << block.substr(0, 20) << " ... " <<
                                            block.substr(len - 20) << "'\n";
        }
        else if (isprint(d_token__) || d_token__ > 0xff)
            std::cout << ", text: `" << d_scanner.matched() << "'\n";
        else
            std::cout << '\n';
    }
}
