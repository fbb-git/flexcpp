#include "dfarow.ih"

void DFARow::tabulateFinals(Table &table) const
{
    ostringstream out;

    for 
    (
        auto iter = d_finAcInfo.begin(), end = d_finAcInfo.end(); 
            iter != end;
                ++iter
    )
    {                           // fixed final length or other final length
        if (iter->final() >= 0) // (possibly incrementing after A++)        
            out << iter->rule() << ':' << iter->final() << ',';
        else if (iter->final() == FinAcInfo::FINAL_NOT_SET)
            out << iter->rule() << ',';
    }

    std::string const &str = out.str();
    if (str.length() > 0)
        table << str.substr(0, str.length() - 1) ;
    else
        table << ' ';
}







