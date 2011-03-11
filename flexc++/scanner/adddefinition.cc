#include "scanner.ih"

void Scanner::addDefinition(SemVal const &nm, SemVal const &def)
{
    string name = SemVal::downCast<TextVal>(nm).str();
    string namePattern = '{' + name + '}';

    if (d_nameExpansion.find(namePattern) != d_nameExpansion.end())
        emsg << "pattern '" << name << "' multiply defined" << endl;
    else
        d_nameExpansion[namePattern] = '(' + 
                                SemVal::downCast<TextVal>(def).str() +
                                        ')';
}
