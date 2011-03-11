#include "dfarow.ih"

void DFARow::tabulateFinals(Table &table) const
{
    auto firstRule = d_finAcInfo.end();

    for 
    (
        auto iter = d_finAcInfo.begin(), end = d_finAcInfo.end(); 
            iter != end;
                ++iter
    )
    {
        if 
        (
            iter->final() >= 0 
            ||
            iter->inc()
            || 
            iter->final() == FinAcInfo::FINAL_NOT_SET
        )
            firstRule = iter;
    }


    if (firstRule == d_finAcInfo.end())
        table << ' ';
    else
    {
        ostringstream out;
        if 
        (
            firstRule->final() == 0 
            ||
            firstRule->inc()
            || 
            firstRule->final() == FinAcInfo::FINAL_NOT_SET
        )
            out << firstRule->rule();
        else if (firstRule->final() > 0) 
            out << firstRule->rule() << ':' << firstRule->final();

        table << out.str();
    }
}








