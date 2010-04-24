#include "state.ih"

void State::nextAccept()
{
    switch (d_accept)
    {
        case NONE:
            d_accept = FIXED_HEADSIZE;
        break;

        case FIXED_HEADSIZE:
            d_accept = PRE_VARIABLE;
        break;

        case PRE_VARIABLE:
            d_accept = VARIABLE_HEADSIZE;
        // FALLING THROUGH

        default:
        break;
    }
}

