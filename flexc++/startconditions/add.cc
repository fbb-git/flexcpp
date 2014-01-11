#include "startconditions.ih"

void StartConditions::add(string const &name, bool underscoresOK)
{
    if (not d_acceptRules)
        return;

    if (find(name) != d_scVector.end())
        emsg << "start condition `" << name << "' multiply defined" << endl; 
    else 
    {
        if (not underscoresOK && name.length() >= 2)
        {
            size_t pos = name.rfind("__");
            if (pos == name.length() - 2)
            {
                emsg << "start condition name (" << name << 
                                        ") may not end in __" << endl;
                return;
            }
        }
        d_scVector.push_back(KeyValue(name, {d_type}));
    }
}
