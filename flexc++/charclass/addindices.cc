#include "charclass.ih"

void CharClass::addIndices(std::set<char> &dest, 
                                size_t begin, size_t end) const
{
//    cout << "\tADD INDICES: " << begin << " up to " << end << '\n';

    for (; begin != end; ++begin)
    {
//        cout << " " << d_chars[begin].first;
        dest.insert(d_chars[begin].first);
    }
}
