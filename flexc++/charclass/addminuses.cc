#include "charclass.ih"

void CharClass::addMinuses(size_t offset, string const &str)
{
    size_t idx = 0;
    while ((idx = str.find('-', idx)) != string::npos)
        d_tag.push_back(offset + idx++);
}
