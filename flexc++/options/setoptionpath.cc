#include "options.ih"

//     1           2           3       4
// --target     %target     --dest   %dest       action:
// ------------------------------------------------------
//     0           0           1       0           2
//     0           0           1       1           2
//     0           1           1       0           2
//     0           1           1       1           2
//     1           0           1       0           2
//     1           0           1       1           2
//     1           1           1       0           2
//     1           1           1       1           2
//     0           0           0       1           2
//     0           1           0       1           2
//     1           0           0       1           2
//     1           1           0       1           2
//     1           0           0       0           1
//     1           1           0       0           1
//     0           1           0       0           1
//     0           0           0       0           1
// -------------------------------------------------------


void Options::setOptionPath(string *dest, int optChar, 
                            string const &defaultFilename,
                            char const *defaultSuffix, 
                            char const *optionName)
{
    Arg::instance().option(dest, optChar);  // try to get the option

    if (dest->find('/') != string::npos)
        emsg << '`' << optionName << "' option: no path names" << endl;
    else 
    {
        if (dest->empty())                  // no value in dest: use a default
            *dest = defaultFilename + defaultSuffix;  // filename and suffix

        *dest = d_targetDirectory + *dest; // prefix the target (may be empty)
    }

    s_warnOptions.insert(optionName);
}
        





