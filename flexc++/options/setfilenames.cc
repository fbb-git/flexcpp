#include "options.ih"

void Options::setFilenames()
{
    if (d_filenames.size())
        emsg << "%filenames multiply specified" << endl;
    else
        d_filenames = undelimit(*d_matched);
}
