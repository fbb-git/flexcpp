#include "dfarow.ih"

void DFARow::tabulateFinals(Table &table) const
{
    ostringstream out;
 
    std::set<size_t> finalStates = d_finalRule;

    for 
    (
        auto iter = d_FinAcInfo.begin(), end = d_FinAcInfo.end(); 
            iter != end;
                ++iter
    )
    {
        if (iter->final() >= 0)
        {
            out << iter->rule() << ':' << iter->final() << ' ';
            finalStates.erase(iter->rule());
        }
    }
    out << ' ';
    
    std::copy(finalStates.begin(), finalStates.end(), //endFinal, 
                    std::ostream_iterator<size_t>(out, ","));

    std::string const &str = out.str();
    if (str.length() > 0)
        table << str.substr(0, str.length() - 1) ;
    else
        table << ' ';
}








