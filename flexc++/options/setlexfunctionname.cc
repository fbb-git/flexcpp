#include "options.ih"

void Options::setLexFunctionName(string const &name)
{
    if (d_lexFunctionName.size())
        emsg << "%lex-function-name multiply specified" << endl;
    else
        d_lexFunctionName = undelimit(name);
}
