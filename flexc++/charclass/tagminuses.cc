#include "charclass.ih"

void CharClass::tagMinuses(size_t offset, string const &str, size_t from)
{
    while ((from = str.find('-', from)) != string::npos)
        d_tag.push_back(offset + from++);
}
