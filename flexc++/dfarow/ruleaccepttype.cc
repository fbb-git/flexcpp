#include "dfarow.ih"

size_t DFARow::ruleAcceptType() const
{
    return d_rule == -1 ?
                0
            :
                static_cast<size_t>(acceptState().accept());
}

