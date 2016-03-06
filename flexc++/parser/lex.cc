#include "parser.ih"

int Parser::lex()
{
    print();
    ++d_tokenCount;

//    if (d_nlAtEOF)
//        return 0;
//
//    if (d_nlAfterBlock)
//    {
//        d_nlAfterBlock = false;
//        return '\n';
//    }
//
//    int token = d_scanner.pLex();
//
//    if (token == BLOCK) 
//       d_nlAfterBlock = true;
//    else if (token == 0)
//    {
//        d_nlAtEOF = true;
//        return '\n';
//    }

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



