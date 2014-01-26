#include "options.ih"

void Options::setLexFunctionName(TextType textType)
{
    if (d_lexFunctionName.size())
        emsg << "%lex-function-name multiply specified" << endl;
    else
        d_lexFunctionName = textOf(textType);
}
