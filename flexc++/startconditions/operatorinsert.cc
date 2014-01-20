#include "startconditions.ih"

ostream &operator<<(ostream &out, StartConditions const &startConditions)
{
    for (auto &element: startConditions.d_scVector)
    {
        out << "Rules active for `" << element.first << "':\n";
        copy (element.second.d_rules.begin(), element.second.d_rules.end(), 
                ostream_iterator<size_t>(out, ", "));
        out << '\n';
    }
    return out;
}
