#include "range.ih"

std::unordered_map<std::string, std::set<char>> Range::s_hash =
{
    { "[:alnum:]" , set<char>()  },
    { "[:alpha:]" , set<char>() },
    { "[:blank:]" , set<char>() },
    { "[:cntrl:]" , set<char>() },
    { "[:digit:]" , set<char>() },
    { "[:graph:]" , set<char>() },
    { "[:lower:]" , set<char>() },
    { "[:print:]" , set<char>() },
    { "[:punct:]" , set<char>() },
    { "[:space:]" , set<char>() },
    { "[:upper:]" , set<char>() },
    { "[:xdigit:]", set<char>() },

    { "[:^alnum:]" , set<char>() },
    { "[:^alpha:]" , set<char>() },
    { "[:^blank:]" , set<char>() },
    { "[:^cntrl:]" , set<char>() },
    { "[:^digit:]" , set<char>() },
    { "[:^graph:]" , set<char>() },
    { "[:^lower:]" , set<char>() },
    { "[:^print:]" , set<char>() },
    { "[:^punct:]" , set<char>() },
    { "[:^space:]" , set<char>() },
    { "[:^upper:]" , set<char>() },
    { "[:^xdigit:]", set<char>() },
};


std::unordered_map<std::string, int (*)(int)> Range::s_funHash =
{
    { "[:alnum:]" , isalnum },
    { "[:alpha:]" , isalpha },
    { "[:blank:]" , isblank },
    { "[:cntrl:]" , iscntrl },
    { "[:digit:]" , isdigit },
    { "[:graph:]" , isgraph },
    { "[:lower:]" , islower },
    { "[:print:]" , isprint },
    { "[:punct:]" , ispunct },
    { "[:space:]" , isspace },
    { "[:upper:]" , isupper },
    { "[:xdigit:]", isxdigit },
};
