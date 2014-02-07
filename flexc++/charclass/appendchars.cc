#include "charclass.ih"

void CharClass::appendChars(std::string const &str, CharType type)
{
    for (char ch: str)
        d_chars.push_back({ch, type});
}
