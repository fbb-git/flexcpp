#ifndef INCLUDED_TEXTVAL_
#define INCLUDED_TEXTVAL_

#include <string>
#include "../semval/semval.h"

class TextVal: public SemVal
{
    std::string d_text;

    public:
        TextVal(std::string str = "");
        std::string const &str() const;

        static spSemVal trimmed(std::string const &str);
        static spSemVal plain(std::string const &str);
        static spSemVal &cat(spSemVal &lhs, spSemVal const &rhs);
};

inline TextVal::TextVal(std::string str)
:
    d_text(str)
{}

inline std::string const &TextVal::str() const
{
    return d_text;
}

#endif
