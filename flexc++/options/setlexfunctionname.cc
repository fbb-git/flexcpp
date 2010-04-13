#include "options.ih"

void Options::setLexFunctionName(string const &name)
{
    if (d_lexFunctionName.size())
        cerr << "%option lexfunctionname (--lexfunctionname) specified "
                                                    "multiple times\n";
    else
        d_lexFunctionName = undelimit(name);
}
