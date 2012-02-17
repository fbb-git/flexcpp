#include "options.ih"

void Options::setFilenames(string const &name)
{
    if (d_filenames.size())
        emsg << "%filenames multiply specified" << endl;
    else
        d_filenames = undelimit(name);
}
