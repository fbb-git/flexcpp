#include "charclass.ih"

void CharClass::addSet(vector <size_t> &minus, size_t offset, 
                        string const &str)
{
    size_t idx = 0;
    while ((idx = str.find('-', idx)) != string::npos)
        minus.push_back(offset + idx);
}
