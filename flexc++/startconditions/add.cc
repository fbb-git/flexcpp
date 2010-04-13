#include "startconditions.ih"

void StartConditions::add(SemVal const &nameVal)
{
    string const &name = strOf(nameVal);

    if (name == "INITIAL")      // Initial is defined by default by us.
        return;

    if (d_hash.find(name) != d_hash.end())
        lineMsg() << "start condition `" << name << "' multiply defined" << 
                                                                        err; 
    else
        d_hash[name] = {d_type};
}
