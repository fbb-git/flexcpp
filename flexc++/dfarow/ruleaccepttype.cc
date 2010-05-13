#include "dfarow.ih"

namespace{
    char xlat[] = 
    {
        ' ',
        '!',
        'F',
        'V'
    };
}

char DFARow::ruleAcceptType(size_t rule) const
{
//X    return xlat[acceptState(rule).accept()];
    return ' ';
}

