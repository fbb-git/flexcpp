#include "options.ih"

void Options::setLexFunctionName()
{
    if (d_lexFunctionName.size())
        emsg << "%lex-function-name multiply specified" << endl;
    else
        d_lexFunctionName = undelimit(*d_matched);
}
