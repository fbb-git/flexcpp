#include "parser.ih"

int Parser::lex()
{
    static bool nlAfterBlock = false;        // to compensate for  missing \n at
                                        // the end of crippled input files

    static bool nlAtEOF = false;

    print();
    ++d_tokenCount;

    if (nlAtEOF)
        return 0;

    if (nlAfterBlock)
    {
        nlAfterBlock = false;
        return '\n';
    }

    int token = d_scanner.pLex();

    if (token == BLOCK) 
       nlAfterBlock = true;
    else if (token == 0)
    {
        nlAtEOF = true;
        return '\n';
    }

    return token;
}



