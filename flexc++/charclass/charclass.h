#ifndef INCLUDED_CHARCLASS_
#define INCLUDED_CHARCLASS_

#include <vector>
#include <string>
#include <set>
#include <ostream>

class CharClass
{
    friend std::ostream &operator<<(std::ostream &out, CharClass const &cc);

    typedef std::vector<std::pair<char, bool>> Vector;
    Vector d_chars;

    public:
        CharClass() = default;
        std::string str() const;        // the chars in the set

        static CharClass unite(CharClass const &lhs, CharClass const &rhs);
        static CharClass difference(CharClass const &lhs, 
                                    CharClass const &rhs);

        static CharClass elements(std::string const &chars, size_t skip);
        CharClass &concatenate(CharClass const &rhs);

        static CharClass escape(std::string const &match);
        static CharClass predefined(std::string const &range);
                
        CharClass negate() const;
        CharClass negate(CharClass const &rhs);

        bool empty() const;

    private:
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

inline bool CharClass::empty() const
{
    return d_chars.empty();
}

inline CharClass CharClass::negate(CharClass const &right)
{
    return concatenate(right).negate();
}

#endif

