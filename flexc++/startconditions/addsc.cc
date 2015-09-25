#include "startconditions.ih"

void StartConditions::addSC(string const &name)
{
    auto iter = d_sc.find(name);

    if (iter == d_sc.end())     // done if the name isn't a startcondition
    {
        emsg << "cannot find start condition `" << name << '\'' << endl;
        return;
    }

    auto iterSC = find(d_active.begin(), d_active.end(), &iter->second);

    if (iterSC != d_active.end())   // done if this name was already specified
    {
        wmsg << "start condition `" << name << "' multiply specified" << endl;
        return;
    }

        // add this StartCondition to the active set
    d_active.push_back(&iter->second);  
}


