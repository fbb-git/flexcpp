#include "parser.ih"

int Parser::lex()
{
    static bool nlAtEOF = false;        // to compensate for  missing \n at
                                        // the end of crippled input files

    print();
    ++d_tokenCount;

    if (nlAtEOF)
        return 0;        

    int token = d_scanner.pLex();

    if (token != 0)                     // not yet at eof
        return token;

    nlAtEOF = true;                     // here we're at EOF: by returning a
                                        // \n the parser is fooled into 
                                        // believing that a \n was seen
                                        // just before the real EOF
    return '\n';
}



