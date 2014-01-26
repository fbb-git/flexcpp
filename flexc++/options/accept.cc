#include "options.ih"

void Options::accept(string const &text, 
                     PathType pathType, char const *declTxt)
{
    if (pathType == FILENAME && text.find('/') != string::npos)
        emsg << '`' << declTxt << "' option/directive: no path names" << endl;
}
