#include "dfa.ih"

void DSupport::outLine(Element const &element, ostream &out)
{
    if (element.width == 0)
        return;

    if (element.type == SKIP)
        out << setw(element.width) << " ";
    else
        out << setfill('-') << setw(element.width) << "-" << setfill(' ');
}
