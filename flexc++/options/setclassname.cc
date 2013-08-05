#include "options.ih"

void Options::setClassName(string const &name)
{
    if (d_className.size())
        emsg << "%class-name multiply specified" << endl;
    else
        d_className = undelimit(name);

    s_warnOptions.insert("class-name");
}

