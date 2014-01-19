#include "startconditions.ih"

void StartConditions::define(string const &name)
{
    if (not d_acceptRules)
        return;

    if (find(name) != d_scVector.end())
        emsg << "start condition `" << name << "' multiply defined" << endl; 
    else 
        d_scVector.push_back(KeyValue(name, {d_type}));
}
