#include "dfarow.ih"

void DFARow::outAccept(size_t rule, ostream &out, DFARow const &obj)
{
    out << obj.acceptType(rule) << ',';
}
