#include "startconditions.ih"

void StartConditions::add(string const &name)
{
    if (name == "INITIAL")      // Initial is defined by default by us.
        return;

    if (d_hash.find(name) != d_hash.end())
        emsg << "start condition `" << name << "' multiply defined" << endl; 
    else
        d_hash[name] = {d_type};
}
