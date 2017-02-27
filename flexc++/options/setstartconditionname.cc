#include "options.ih"

void Options::setStartConditionName(TextType textType)
{
    if (d_startConditionName.size())
        emsg << "%startcondition-name multiply specified" << endl;
    else
        d_startConditionName = textOf(textType);

    s_warnOptions.insert("startcondition-name");
}

