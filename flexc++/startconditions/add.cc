#include "startconditions.ih"

void StartConditions::add(string const &name, bool underscoresOK)
{
    if (d_hash.find(name) != d_hash.end())
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
        d_hash[name] = {d_type};
    }
}
