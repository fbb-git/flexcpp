#include "options.ih"

void Options::assign(std::string *target, PathType pathType, 
                                          char const *declTxt)
{
    if (target->empty())
    {
        s_warnOptions.insert(declTxt);
        *target = undelimit(accept(pathType, declTxt));
    }
    else
        emsg << "%" << declTxt << " multiply specified" << endl;
}
        
