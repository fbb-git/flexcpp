#include "dfarow.ih"

void DFARow::tabulateFinals(Table &table) const
{
    ostringstream out;
 
//X   std::set<size_t> finalStates = d_finalRule;

    for 
    (
        auto iter = d_finAcInfo.begin(), end = d_finAcInfo.end(); 
            iter != end;
                ++iter
    )
    {
        if (iter->final() >= 0)
        {
            out << iter->rule() << ':' << iter->final() << ',';
//X           finalStates.erase(iter->rule());
        }
        else if (iter->final() == FinAcInfo::FINAL_NOT_SET)
            out << iter->rule() << ',';
    }
//X   out << ' ';
    
//X   std::copy(finalStates.begin(), finalStates.end(), //endFinal, 
//X                   std::ostream_iterator<size_t>(out, ","));

    std::string const &str = out.str();
    if (str.length() > 0)
        table << str.substr(0, str.length() - 1) ;
    else
        table << ' ';
}








