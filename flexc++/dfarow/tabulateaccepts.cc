#include "dfarow.ih"

void DFARow::tabulateAccepts(Table &table) const
{
    ostringstream out;
    for 
    (
        auto iter = d_accCount.begin(), end = d_accCount.end(); 
            iter != end;
                ++iter
    )
    {
        AccCount::Type type = iter->type();      // get the accCount flags

        if (type & (AccCount::COUNT | AccCount::INCREMENTING))
        {
            out << iter->rule() << ':';

            if (type &AccCount::INCREMENTING)
                out << "+";
            else
                out << iter->accCount();

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




