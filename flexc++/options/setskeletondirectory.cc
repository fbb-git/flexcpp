#include "options.ih"

void Options::setSkeletonDirectory(string const &name)
{
    if (d_skeletonDirectory.size())
        emsg << "%skeleton-directory multiply specified" << endl;
    else
        setPath(&d_skeletonDirectory, name);
}
