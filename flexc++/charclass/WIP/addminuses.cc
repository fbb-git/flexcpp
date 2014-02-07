#include "charclass.ih"

void CharClass::addMinuses(vector <size_t> &minus, size_t offset, 
                           string const &str)
{
//cerr << "addSet in\n";
    while ((offset = str.find('-', offset)) != string::npos)
        minus.push_back(offset++);
//cerr << "addSet out\n";
}
