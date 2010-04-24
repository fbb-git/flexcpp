#include "dfarow.ih"

string DFARow::acceptType() const
{
    string ret;

    if (d_rule == -1)                   // not an accepting row
        return ret;

    ret = X2a(d_rule).str() + '-' +
        (
            (*d_states)[(*d_rules)[d_rule].accept()].accept() == 
            State::VARIABLE_HEADSIZE ?
                'V'
            :
                'F'
        );

    return ret;

}
