#ifndef INCLUDED_CHARCLASS_
#define INCLUDED_CHARCLASS_

#include <set>
#include <string>

#include "../semval/semval.h"

class CharClass: public SemVal
{
    std::set<char> d_set;

    std::string d_last;  // at most the last 2 characters

    public:
        std::string str() const;        // the chars in de charset

        static spSemVal plain(char ch);
        static spSemVal escape(std::string const &match);
        static spSemVal predefined(std::string const &range);
                
        static spSemVal &concatenate(spSemVal &lhs, SemVal const &rhs);
        static spSemVal &addLeftoverChars(spSemVal &charClass);
        static spSemVal difference(SemVal const &lhs, SemVal const &rhs);
        static spSemVal &unite(spSemVal &lhs, SemVal const &rhs);
        static spSemVal negate(spSemVal const &charClass);

    private:
        CharClass();
        CharClass(char ch);
        CharClass(std::string const &str);
        CharClass(std::set<char> const &charSet);

        void addSet(std::set<char> const &rhs);
        void addSet(std::string const &str);
        void addRange(char from, char to);

                                                    // lhs.d_last has 1 char
        void static concatenate1(CharClass &lhs, std::string const &rChars);
                                                    // lhs.d_last has 2 chars
        void static concatenate2(CharClass &lhs, std::string const &rChars);

};

#endif


