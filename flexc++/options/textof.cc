#include "options.hh"

string const &Options::textOf(TextType type)
{
    switch (type)
    {
        case TextType::RAWSTRING:
        return *d_rawString;

        case TextType::STRING:
            if (d_matched->find('"') == 0 )
                return d_undelimit = 
                        d_matched->substr(1, d_matched->size() - 2);
        // FALLING THROUGH

        case TextType::IDENT:
        return *d_matched;

        default:    // not reached, but added to prevent the 'control
        throw 1;    // reaches the end of non-void function' warning.
    };
}
