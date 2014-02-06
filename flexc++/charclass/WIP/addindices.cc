#include "charclass.ih"

void CharClass::addChars(std::set<char> &dest, size_t begin, size_t end) const
{
//    cout << "\tADD INDICES: " << begin << " up to " << end << '\n';

    for (; begin != end; ++begin)
        dest.insert(d_chars[begin].first);
}
