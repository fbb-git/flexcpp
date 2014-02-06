#include "charclass.ih"

void CharClass::addRange(std::set<char> &dest, size_t idx) const
{
    for (
        size_t begin = static_cast<unsigned char>(d_chars[idx - 1].first),
                 end = static_cast<unsigned char>(d_chars[idx + 1].first) + 1;
            begin != end;
                ++begin
    )
        dest.insert(begin);
}
