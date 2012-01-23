#include "parser.ih"

int Parser::lex()
{
    print();
    ++d_tokenCount;
    return d_scanner.pLex();
}

