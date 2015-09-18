#include "options.hh"

void Options::assign(TextType textType, std::string *target, 
                     PathType pathType, char const *declTxt)
{
    if (not target->empty())
        emsg << "%" << declTxt << " multiply specified" << endl;
    else
    {
        s_warnOptions.insert(declTxt);
        accept(*target = textOf(textType), pathType, declTxt);
    }
}
        
