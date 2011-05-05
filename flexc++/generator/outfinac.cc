#include "generator.ih"

void Generator::outFinAc(FinAcInfo const &finac, ostream &out, size_t &idx)
{
    out << 
        "     {" << setw(2) << finac.rule() << ',' << finac.info() << ',' <<
                    setw(2) << finac.accept() << "},  // " << idx++ << '\n';
}


