#include "generator.ih"

void Generator::outFinAc(FinAcInfo const &finac, ostream &out)
{
    enum Conflict
    {
        NO_CONFLICT,
        ALSO_PLAIN_FINAL_STATE,
    };

    out << 
        "         {" <<
           setw(2) << finac.rule() << ',';              // show the matching
                                                        // rule 
    int final = finac.final();
    int accept = finac.accept();

    Conflict conflict = NO_CONFLICT;

    if (accept >= 0)
    {
//        if (final == FinAcInfo::FINAL_NOT_SET)
//            conflict = ALSO_PLAIN_FINAL_STATE;
        out << setw(2) << accept << ',' << setw(2) << finac.inc();
    }
    else 
        out << (final == FinAcInfo::FINAL_NOT_SET ? "-1," : "-2,") << " 0";
        
    out <<  "},";

    if (conflict)
        out << " // CONFLICT";

    out << "\n";
}


