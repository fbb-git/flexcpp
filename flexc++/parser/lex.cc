#include "parser.ih"

int Parser::lex()
{
    print();
    ++d_tokenCount;

    int token = d_scanner.pLex();
    if (token == 0)
    {
        token = '\n';
        d_scanner.atEndOfInput();
    }

    return token;
}

