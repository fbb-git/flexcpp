#include "charclass.hh"

void CharClass::addChars(std::set<char> &dest, size_t begin, size_t end) const
{
    dest.insert(d_str.begin() + begin, d_str.begin() + end);
}
