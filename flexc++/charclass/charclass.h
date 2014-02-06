#ifndef INCLUDED_CHARCLASS_
#define INCLUDED_CHARCLASS_

#include <vector>
#include <string>
#include <set>
#include <ostream>

class CharClass
{
    friend std::ostream &operator<<(std::ostream &out, CharClass const &cc);

    enum CharType
    {
        CHAR,
        PREDEF,
        RANGE,
        MINUS           // is converted to either CHAR or RANGE
    };

        // the bool indicates that the char belongs to a predefined range.
        // this is used when merging elements of the set: a '-' cannot follow 
        // or be followed by characters from a predefined range.
    typedef std::vector<std::pair<char, bool>> Vector;
    Vector d_chars;

    public:
        CharClass() = default;
        std::string str() const;        // Determine the (final) set of
                                        // characters (using `set()') and 
                                        // return them as a std::string

                                        // create a class containing the 
                                        // the set of chars defined by 'chars'
                                        // startign at idx 'skip'
        static CharClass elements(std::string const &chars, size_t skip);

                                        // add the set of chars in rhs to
                                        // the current set of chars
        CharClass &concatenate(CharClass const &rhs);

                                        // Call unescape on match, and return
                                        // the CharClass containing the 
                                        // resulting characters
        static CharClass escape(std::string const &match);

                                        // use CharRange to determine the set
                                        // of predefined chars, and return the
                                        // set as a CharClass object.
        static CharClass predefined(std::string const &range);
                
        CharClass negate() const;       // pass the current set of characters
                                        // (determined by set()) to
                                        // CharRange::negate, and return the
                                        // resulting CharClass

                                        // Concatenate the current set and rhs
                                        // and return the CharClass returned
                                        // by negate().
        CharClass negate(CharClass const &rhs);

                                        // merge two existing sets
                                        // return a new one
        static CharClass unite(CharClass const &lhs, CharClass const &rhs);

                                        // return a new set containing the lhs
                                        // elements not found in the rhs set
        static CharClass difference(CharClass const &lhs, 
                                    CharClass const &rhs);

        bool empty() const;             // true if the set is empty.

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

