#include "dfarow.ih"

void DFARow::tabulate(Table &table) const
{
                                    // only display the ranges that are used 
    for (size_t idx = 0, end = d_ranges->size(); idx++ != end; )
    {
        if (not d_ranges->used(idx))
            continue;

        auto iter = d_map.find(idx);
        if (iter == d_map.end())
            table << ' ';
        else
            table << iter->second;
    }

    ostringstream out;
    for 
    (
        auto iter = d_LARule.begin(), end = d_LARule.end(); 
            iter != end;
                ++iter
    )
    {
        if (iter->final() >= 0)
            out << iter->rule() << ':' << iter->final() << ',';
    }
    out << ' ';
    
    if (d_finalRule.size())
    {
        copy(d_finalRule.begin(), d_finalRule.end(), 
                ostream_iterator<size_t>(out, ","));
    }

    string const &str = out.str();
    if (str.length() > 0)
        table << str.substr(0, str.length() - 1) ;
    else
        table << ' ';

    table << accepts();
}




