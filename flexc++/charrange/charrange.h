#ifndef INCLUDED_CHARRANGE_
#define INCLUDED_CHARRANGE_

#include <string>
#include <bobcat/linearmap>

class CharRange
{
    struct AllString;

    static FBB::LinearMap<std::string, std::string>     s_hash;
    static FBB::LinearMap<std::string, int (*)(int)>    s_funHash;
    static std::string s_all;

    public:
        static std::string const &predefined(std::string const &className);
        static std::string negate(std::string const &str);
};
        
#endif
