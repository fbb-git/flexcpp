#ifndef INCLUDED_CHARCLASS_
#define INCLUDED_CHARCLASS_

#include <vector>
#include <string>
#include <set>

#include "../semval/semval.h"

class CharClass: public SemVal
{
    typedef std::vector<std::pair<char, bool>> Vector;
    Vector d_chars;

    public:
        std::string str() const;        // the chars in the set

        static spSemVal plain(char ch);
        static spSemVal escape(std::string const &match);
        static spSemVal predefined(std::string const &range);
                
        static spSemVal &concatenate(spSemVal &lhs, SemVal const &rhs);
        static spSemVal difference(SemVal const &lhs, SemVal const &rhs);
        static spSemVal unite(spSemVal &lhs, SemVal const &rhs);
        static spSemVal negate(spSemVal const &charClass);
        static spSemVal negate(spSemVal &lhs, SemVal const &rhs);

    private:
static void display(Vector const &vect);


        CharClass();
        CharClass(char ch);
        CharClass(std::string const &str);
        CharClass(std::set<char> const &charSet);

        std::set<char> set() const;                 // create a set (or F)


        void addRange(std::set<char> &charSet, size_t idx) const;
        void addIndices(std::set<char> &dest, size_t begin, size_t end) const;
        void addChars(std::set<char> &dest, size_t begin, size_t end) const;
        size_t findRange(size_t from) const;        // find a range fm 'from'
        bool validRange(size_t idx) const;          // T if valid range,
                                                    // idx at '-'
};

#endif

