#include "dfarow.ih"

void DFARow::tabulateAccepts(Table &table) const
{
    ostringstream out;
    for 
    (
        auto iter = d_tailCount.begin(), end = d_tailCount.end(); 
            iter != end;
                ++iter
    )
    {
        TailCount::Type type = iter->type();      // get the tailCount flags

        if (type & (TailCount::COUNT | TailCount::INCREMENTING))
        {
            out << iter->rule() << ':';

            if (type &TailCount::INCREMENTING)
                out << "+";
            else
                out << iter->tailCount();

            out  << ',';
        }
//        else
//            out << '-';

    }

    std::string const &str = out.str();
    if (str.length() > 0)
        table << str.substr(0, str.length() - 1) ;
    else
        table << ' ';
}




