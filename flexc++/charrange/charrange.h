#ifndef INCLUDED_CHARRANGE_
#define INCLUDED_CHARRANGE_

#include <unordered_map>
#include <set>
#include <string>

class CharRange
{
    static std::unordered_map<std::string, std::set<char>> s_hash;
    static std::unordered_map<std::string, int (*)(int)>   s_funHash;

    public:
        static std::set<char> const &predefined(std::string const &className);
        static std::set<char> negate(std::set<char> const &cSet);
};
        
#endif
