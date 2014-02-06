#include "charclass.ih"

    // receives ESCAPE_SEQUENCE: 1 char.

CharClass CharClass::escape(string const &match)
{
    CharType type = (match.length() == 2 && match[1] == '-' ? CHAR : MINUS);
    
    CharClass ret(String::unescape(match)[0], type);
    return ret;
}
