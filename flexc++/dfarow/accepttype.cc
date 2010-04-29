#include "dfarow.ih"

string DFARow::acceptType(size_t rule) const
{
    string ret = X2a(rule).str() + '-' +
        (
            acceptState(rule).accept() == State::VARIABLE_HEADSIZE ?
                'V'
            :
                'F'
        );

    return ret;

}
