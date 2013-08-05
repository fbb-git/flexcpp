#include "options.ih"

void Options::setPath(std::string *target, std::string const &name,
                        char const *warnOption)
{
    if (target->empty())
    {
        *target = undelimit(name);
        s_warnOptions.insert(warnOption);
    }
    
}
        
