#include "options.ih"

void Options::setClassName()
{
    if (d_className.size())
        emsg << "%class-name multiply specified" << endl;
    else
        d_className = undelimit(*d_matched);

    s_warnOptions.insert("class-name");
}

