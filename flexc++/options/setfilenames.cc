#include "options.hh"

void Options::setFilenames(TextType textType)
{
    if (d_filenames.size())
        emsg << "%filenames multiply specified" << endl;
    else
        d_filenames = textOf(textType);
}
