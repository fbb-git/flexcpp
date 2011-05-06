#include "dfarow.ih"

void DFARow::tabulateAccepts(Table &table) const
{
    ostringstream out;
    for 
    (
        auto iter = d_finAc.begin(), end = d_finAc.end(); 
            iter != end;
                ++iter
    )
    {
        if (iter->inc())
            out << iter->rule() << ":++" << iter->accept() << ',';
    }

    std::string const &str = out.str();
    if (str.length() > 0)
        table << str.substr(0, str.length() - 1) ;
    else
        table << ' ';
}
