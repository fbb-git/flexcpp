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
        CHAR,           // any plain character
        PREDEF,         // characters in a predefined range
        END,            // end marker for handleMinusAndEscape
    };

    enum State
    {
        RAW,            // while d_str is initially filled
        PROCESSED,      // when escape chars etc. have been processes
        NEGATED,        // then negate has been called
        FINAL           // at the end of the set-member.
    };
    State d_state = RAW;

    std::string d_str;          // all received (and final) characters 

    typedef std::vector<std::pair<size_t, CharType>> TypeVector;
                                // begin index of characters of type CharType
    TypeVector d_type;

    typedef std::vector<size_t>::iterator TagIter;
    std::vector<size_t> d_tag;  // locations of - chars that could be range
                                // operators.

    public:
        CharClass();
                                        // create a class containing the 
                                        // the raw series of chars defined by
                                        // 'chars', starting at idx 'skip'
        CharClass(std::string const &chars, size_t skip);       // 3

                                        // return the characters in matched,
                                        // prefixed by 'c' (not part of the 
                                        // set)
        static std::string chars(std::string const &matched);

                                        // use CharRange to determine the set
                                        // of predefined chars, and return the
                                        // raw series of characters, prefixed
                                        // by 'p' (not part of the set)
        static std::string predefined(std::string const &name);

                                        // add the chars in the vector's
                                        // strings. Add the string's chars
                                        // beyond the first char to d_chars 
                                        // as PREDEF if str[0] == 'p'm 
                                        // otherwise as CHAR
        void append(std::vector<std::string> const &strings);

        void negate();                  // negate the current set of 
                                        // characters

                                        // Append(strings) and then negate.
        void negate(std::vector<std::string> const &strings);

        std::string const &str();       // Determine the (final) set of
                                        // characters (using `set()') and 
                                        // return them as a std::string

                                        // merge two existing sets
                                        // return a new one
        static CharClass unite(CharClass &lhs, CharClass &rhs);

                                        // return a new set containing the lhs
                                        // elements not found in the rhs set
        static CharClass difference(CharClass &lhs, CharClass &rhs);

        bool empty() const;             // true if the set is empty.
                                        // (used by Pattern::characterClass)
    private:
        std::set<char> set();                       // create a set (or F)
        void handleMinusAndEscape();
        void inspect(TypeVector::iterator iter);
        void tagMinuses(size_t offset, std::string const &str, size_t from);
        void replace(std::string newStr, TypeVector::iterator iter, 
                     size_t end);

        bool validRange(TagIter iter) const;        // T if valid range,
                                                    // idx at '-'
        bool predefinedBefore(size_t idx) const;
        bool predefinedAfter(size_t idx) const;
        bool isPredefined(size_t idx) const;        // true if at idx a PREDEF
                                                    // char is found
        bool rangeAfterRange(TagIter iter) const;
        bool inversedRange(size_t idx) const;
        std::string rangeString(size_t idx) const;
        void addChars(std::set<char> &dest, size_t begin, size_t end) const;
        void addRange(std::set<char> &charSet, size_t idx) const;
};

inline bool CharClass::empty() const
{
    return d_str.empty();
}

#endif



