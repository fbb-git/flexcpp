#ifndef INCLUDED_CHARCLASS_
#define INCLUDED_CHARCLASS_

#include <vector>
#include <string>
#include <set>

#include "../utility/utility.h"

class CharClass
{
    typedef std::vector<std::pair<char, bool>> Vector;
    Vector d_chars;

    public:
        CharClass() = default;
        std::string str() const;        // the chars in the set

        static CharClass unite(CharClass const &lhs, CharClass const &rhs);
        static CharClass difference(CharClass const &lhs, 
                                    CharClass const &rhs);

        static CharClass elements(std::string const &chars, size_t skip);
        static CharClass &concatenate(CharClass &lhs, CharClass const &rhs);

        static CharClass escape(std::string const &match);
        static CharClass predefined(std::string const &range);
                
        static CharClass negate(CharClass const &charClass);
        static CharClass negate(CharClass &lhs, CharClass const &rhs);

    private:
        static void display(Vector const &vect);


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

template <>                                     // two specializations:
struct Type<CharClass>                         // defining 'DataType'
{                                               // given CharClass
    enum { dataType = DataType::CHARCLASS };
};

template <>                                     // defining 'CharClass'
struct Type<Int<DataType::CHARCLASS>>          // given CHARCLASS
{
    typedef CharClass type;
};


#endif

