#ifndef INCLUDED_CHARRANGE_
#define INCLUDED_CHARRANGE_

#include <set>
#include <string>

#include <bobcat/linearmap>

class CharRange
{
    static FBB::LinearMap<std::string, std::set<char>> s_hash;
    static FBB::LinearMap<std::string, int (*)(int)>   s_funHash;

    public:
        static std::set<char> const &predefined(std::string const &className);
        static std::set<char> negate(std::set<char> const &cSet);
};
        
#endif
