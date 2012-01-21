#include "scanner.ih"

void Scanner::addDefinition(string const &name, string const &def)
{
    string namePattern = '{' + name + '}';

    if (d_nameExpansion.find(namePattern) != d_nameExpansion.end())
        emsg << "pattern '" << name << "' multiply defined" << endl;
    else
{
        d_nameExpansion[namePattern] = '(' + String::trim(def) + ')';
cout << "   DEFINING " << name << " AS: " << d_nameExpansion[namePattern]
<< '\n';
}
}
