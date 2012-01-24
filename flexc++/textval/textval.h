#ifndef INCLUDED_TEXTVAL_
#define INCLUDED_TEXTVAL_

#include <string>

class TextVal
{
    std::string d_text;

    public:
        TextVal(std::string str = "");
        std::string const &str() const;

        static TextVal trimmed(std::string const &str);
        static TextVal &cat(TextVal &lhs, TextVal const &rhs);
};

inline TextVal::TextVal(std::string str)
:
    d_text(str)
{}

inline std::string const &TextVal::str() const
{
    return d_text;
}

inline TextVal TextVal::trimmed(string const &str)
{
    return TextVal(String::trim(str));
}

#endif
