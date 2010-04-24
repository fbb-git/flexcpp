#include "dfarow.ih"

void DFARow::setAcceptType()
{
    if (d_rule != -1)
        acceptState().nextAccept();
}
