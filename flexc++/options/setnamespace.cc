#include "options.ih"

void Options::setNameSpace(string const &name)
{
    if (d_nameSpace.size())
        emsg << "%namespace multiply specified" << endl;
    else
        d_nameSpace = undelimit(name);

    s_warnOptions.insert("namespace");
}
