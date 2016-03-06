#include "parser.ih"

int Parser::lex()
{
    print();
    ++d_tokenCount;

    if (d_nlAtEOF)
        return 0;

    int token = d_scanner.pLex();

    if (token == 0)
    {
        d_nlAtEOF = true;
        return '\n';
    }

    return token;
}



