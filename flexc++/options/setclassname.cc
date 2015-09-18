#include "options.hh"

void Options::setClassName(TextType textType)
{
    if (d_className.size())
        emsg << "%class-name multiply specified" << endl;
    else
        d_className = textOf(textType);

    s_warnOptions.insert("class-name");
}

