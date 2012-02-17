#include "options.ih"

void Options::setTargetDirectory(string const &name)
{
    if (d_targetDirectory.size())
        emsg << "%target-directory multiply specified" << endl;
    else
        setPath(&d_targetDirectory, name);
}
