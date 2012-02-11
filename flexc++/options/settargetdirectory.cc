#include "options.ih"

void Options::setTargetDirectory(string const &name)
{
    if (d_targetDirectory.size())
        cerr << "%target-directory specified multiple times\n";
    else
    {
        setPath(&d_targetDirectory, name);
        if (d_targetDirectory.length() && *d_targetDirectory.rbegin() != '/')
            d_targetDirectory += '/';
    }
}
