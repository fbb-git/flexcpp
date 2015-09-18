#include "scanner.hh"

void Scanner::addDefinition(string const &name, TextType textType)
{
    string namePattern = '{' + name + '}';

    string const &def = matched();

    if (d_nameExpansion.find(namePattern) != d_nameExpansion.end())
        emsg << "pattern '" << name << "' multiply defined" << endl;
    else
        d_nameExpansion[namePattern] = '(' + String::trim(def) + ')';
}
