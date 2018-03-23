#include "scanner.ih"

void Scanner::addDefinition(string const &name)//, 
//                            [[maybe_unused]] TextType textType)
{
    string namePattern = '{' + name + '}';

    string const &def = matched();

    if (d_nameExpansion.find(namePattern) != d_nameExpansion.end())
        emsg << "pattern '" << name << "' multiply defined" << endl;
    else
        d_nameExpansion[namePattern] = '(' + String::trim(def) + ')';
}
