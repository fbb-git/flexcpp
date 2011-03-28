#include "charclass.ih"

void CharClass::addRange(std::set<char> &dest, size_t idx) const
{
    if (idx + 1 == d_chars.size())
    {
        dest.insert(d_chars[idx - 1].first);
        dest.insert(d_chars[idx].first);
        return;
    }
    
    size_t from = static_cast<unsigned char>(d_chars[idx - 1].first);
    size_t to = static_cast<unsigned char>(d_chars[idx + 1].first);

    addChars(dest, from, to + 1);
}
