#include "rules.ih"

void Rules::warnNonViable()
{
    for (auto implied: d_impliedViable)
    {
        if (d_rules[implied.first].viable())
            d_rules[implied.second].setViable(true);
    }
    
            
    for 
    (
        auto begin = d_rules.begin(), iter = begin, end = d_rules.end();
            (iter = find_if(iter, end, nonViable)) != end;
                ++iter
    )
        wmsg << "Rule " << (iter - begin) << " (" << iter->source() << ": " <<
                    iter->lineNr() << ") can never be matched\n";
}
