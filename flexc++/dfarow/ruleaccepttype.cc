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
    return xlat[acceptState(rule).accept()];
}

