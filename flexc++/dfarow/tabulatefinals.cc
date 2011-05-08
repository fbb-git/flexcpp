#include "dfarow.ih"

void DFARow::tabulateFinals(Table &table) const
{
    size_t first = d_finalRule.first;
    size_t second = d_finalRule.second;

    ostringstream out;

    if (first != UINT_MAX)
    {
        out << d_finalRule.first;
        if (second != UINT_MAX)
            out << ',';
    }
    if (second != UINT_MAX)
        out << second;

    table << out.str();

//    auto firstRule = d_accCount.end();
//
//    for         // find the first final rule
//    (
//        auto iter = d_accCount.begin(), end = d_accCount.end(); 
//            iter != end;
//                ++iter
//    )
//    {
//        if (iter->final())
//        {
//            firstRule = iter;
//            break;
//        }
//    }
//
//    if (firstRule == d_accCount.end())
//        table << ' ';
//    else
//    {
//        ostringstream out;
//        if 
//        (
//            firstRule->final() == 0 
//            ||
//            firstRule->inc()
//            || 
//            firstRule->final()
//        )
//            out << firstRule->rule();
//        else if (firstRule->final() > 0) 
//            out << firstRule->rule() << ':' << firstRule->final();
//
//        table << out.str();
//    }
}








