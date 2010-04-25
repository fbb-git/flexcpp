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

char DFARow::ruleAcceptType() const
{
    return d_rule == -1 ?
                ' '
            :
                xlat[acceptState().accept()];
}

