#include "charrange.ih"

FBB::LinearMap<std::string, string> CharRange::s_hash =
{
    { "[:alnum:]" , string() },
    { "[:alpha:]" , string() },
    { "[:blank:]" , string() },
    { "[:cntrl:]" , string() },
    { "[:digit:]" , string() },
    { "[:graph:]" , string() },
    { "[:lower:]" , string() },
    { "[:print:]" , string() },
    { "[:punct:]" , string() },
    { "[:space:]" , string() },
    { "[:upper:]" , string() },
    { "[:xdigit:]", string() },
    { ".",          string() },

    { "[:^alnum:]" , string() },
    { "[:^alpha:]" , string() },
    { "[:^blank:]" , string() },
    { "[:^cntrl:]" , string() },
    { "[:^digit:]" , string() },
    { "[:^graph:]" , string() },
    { "[:^lower:]" , string() },
    { "[:^print:]" , string() },
    { "[:^punct:]" , string() },
    { "[:^space:]" , string() },
    { "[:^upper:]" , string() },
    { "[:^xdigit:]", string() },
};


FBB::LinearMap<std::string, int (*)(int)> CharRange::s_funHash =
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

string  CharRange::s_all = CharRange::AllString();
