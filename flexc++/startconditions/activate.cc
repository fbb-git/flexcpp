#include "startconditions.ih"

void StartConditions::activate(string const &name)
{
    auto iter = d_hash.find(name);

    if (name == "INITIAL")
    {
        d_inclusive = true;         // done if the name is INITIAL
        return;
    }

    if (iter == d_hash.end())       // done if the name isn't a startcondition
    {
        emsg << "cannot find start condition `" << name << '\'' << endl;
        return;
    }
        // rules are also added to INITIAL if a start condition is INCLUSIVE
    d_inclusive = d_inclusive || iter->second.d_type == INCLUSIVE;

    auto iterSC = find(d_active.begin(), d_active.end(), &iter->second);

    if (iterSC != d_active.end())   // done if this name was already specified
    {
        wmsg << "start condition `" << name << "' multiply specified" << endl;
        return;
    }

        // add this StartCondition to the active set
    d_active.push_back(&iter->second);  
}


