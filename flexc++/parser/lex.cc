#include "parser.ih"

int Parser::lex()
{
    print();
//    ++d_patternTokenCount;
    return d_scanner.pLex();
}

