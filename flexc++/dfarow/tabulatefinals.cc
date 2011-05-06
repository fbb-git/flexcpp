#include "dfarow.ih"


void DFARow::tabulateFinals(Table &table) const
{
    auto firstRule = d_finAc.end();

    for         // find the first final rule
    (
        auto iter = d_finAc.begin(), end = d_finAc.end(); 
            iter != end;
                ++iter
    )
    {
        if (iter->final())
        {
            firstRule = iter;
            break;
        }
    }

    if (firstRule == d_finAc.end())
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
            firstRule->final()
        )
            out << firstRule->rule();
        else if (firstRule->final() > 0) 
            out << firstRule->rule() << ':' << firstRule->final();

        table << out.str();
    }
}








