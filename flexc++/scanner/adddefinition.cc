#include "scanner.ih"

void Scanner::addDefinition(spSemUnion const &spName, string const &def)
{
    string const &name = spName->value<SemUnion::STRING>();

    string namePattern = '{' + name + '}';

    if (d_nameExpansion.find(namePattern) != d_nameExpansion.end())
        emsg << "pattern '" << name << "' multiply defined" << endl;
    else
        d_nameExpansion[namePattern] = '(' + String::trim(def) + ')';
}
