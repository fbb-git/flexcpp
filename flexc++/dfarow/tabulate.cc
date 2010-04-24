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

    if (d_finalRule.size())
    {
        ostringstream out;
        copy(d_finalRule.begin(), d_finalRule.end(), 
                ostream_iterator<size_t>(out, ","));
        string const &str = out.str();
        table << str.substr(0, str.length() - 1) ;
    }
    else
        table << ' ';

    table << acceptType();

//    ostringstream os;
//    for 
//    (                                   // show the accept states of rules
//        auto iter = d_acceptRules.begin(), end = d_acceptRules.end(); 
//            iter != end;
//                ++iter
//   )
//        os << iter->first << '-' << 
//                (iter->second == State::INHERITING ? '2' : '1') << ' ';
//    table << os.str().substr(0, os.str().length() - 1);
}

