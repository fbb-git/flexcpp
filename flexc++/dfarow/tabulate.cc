#include "dfarow.ih"

void DFARow::tabulate(Table &table) const
{
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

    if (d_finalRule != UINT_MAX)
        table << d_finalRule;
    else
        table << ' ';

    ostringstream os;
    for 
    (
        auto iter = d_acceptRules.begin(), end = d_acceptRules.end(); 
            iter != end;
                ++iter
   )
        os << (iter->second == State::INHERITING ? 'I' : 'N') << ',' <<
               iter->first << "; ";

    table << os.str().substr(0, os.str().length() - 2);
}
