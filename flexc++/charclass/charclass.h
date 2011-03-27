#ifndef INCLUDED_CHARCLASS_
#define INCLUDED_CHARCLASS_

#include <string>
#include <set>

#include "../semval/semval.h"

class CharClass: public SemVal
{
    mutable std::string d_chars;

    public:
        std::string const &str() const;        // the chars in de charset

        static spSemVal plain(char ch);
        static spSemVal escape(std::string const &match);
        static spSemVal predefined(std::string const &range);
                
        static spSemVal &concatenate(spSemVal &lhs, SemVal const &rhs);
        static spSemVal difference(SemVal const &lhs, SemVal const &rhs);
        static spSemVal &unite(spSemVal &lhs, SemVal const &rhs);
        static spSemVal negate(spSemVal const &charClass);
        static spSemVal negate(spSemVal &lhs, SemVal const &rhs);

    private:
        CharClass();
        CharClass(char ch);
        CharClass(std::string const &str);
        CharClass(std::set<char> const &charSet);

        void addSet(std::set<char> const &charSet);

        std::set<char> set() const;                 // create a set (or F)
        void addRange(std::set<char> &charSet, size_t idx) const;
        void addIndices(std::set<char> &dest, size_t begin, size_t end) const;
        void addChars(std::set<char> &dest, size_t begin, size_t end) const;
        size_t findRange(size_t from) const;        // find a range fm 'from'
        bool a_b_c(size_t idx) const;               // T if 'a-b-c' pattern,
                                                    // idx at 1st '-'
};

#endif

