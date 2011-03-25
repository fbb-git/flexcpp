#include "charclass.ih"

void CharClass::addRange(std::set<char> &dest, size_t idx) const
{
    size_t from = static_cast<unsigned char>(d_chars[idx - 1]);
    size_t to = static_cast<unsigned char>(d_chars[idx + 1]);

    if (from <= to)
        addChars(dest, from, to + 1);
    else
        emsg << "Illegal character range: `" << 
                                d_chars.substr(idx - 1, 3) << '\'' << endl;
}
