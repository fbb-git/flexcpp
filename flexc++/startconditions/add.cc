#include "startconditions.ih"

void StartConditions::add(string const &name)
{
    if (d_hash.find(name) != d_hash.end())
        emsg << "start condition `" << name << "' multiply defined" << endl; 
    else
        d_hash[name] = {d_type};
}
