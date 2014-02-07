#include "charclass.ih"

void CharClass::addChars(std::set<char> &dest, size_t begin, size_t end) const
{
    for (; begin != end; ++begin)
        dest.insert(d_chars[begin].first);
}
