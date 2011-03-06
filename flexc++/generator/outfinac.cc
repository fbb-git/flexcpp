#include "generator.ih"

void Generator::outFinAc(FinAcInfo const &finac, ostream &out)
{
    out << 
        "         {" <<
           setw(2) << finac.rule() << ',' <<
           setw(2) << finac.final() << ',' <<
           setw(2) << finac.accept() << ',' <<
           setw(2) << finac.inc() << "},\n";
}


