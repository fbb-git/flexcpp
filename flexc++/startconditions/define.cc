#include "startconditions.ih"

void StartConditions::define(string const &name)
{
    if (not d_acceptRules)
        return;

    if (d_sc.find(name) != d_sc.end())
        emsg << "start condition `" << name << "' multiply defined" << endl; 
    else 
        d_sc.insert( {name, StartCondition(d_type)} );
}
