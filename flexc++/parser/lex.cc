#include "parser.hh"

int Parser::lex()
{
    print();
    ++d_tokenCount;

    int token = d_scanner.pLex();

    if (token != 0)
        d_atEOF = 0;
    else
    {
        ++d_atEOF;
        token = '\n';
        d_scanner.atEndOfInput();
    }

    if (d_atEOF > 1)
    {
        emsg << "Unexpected End Of Input" << endl;
        return -1;      // recognized by parse.cc's nextToken, which is there
                        // converted to _EOF_, terminating flexc++
    }
    return token;
}

