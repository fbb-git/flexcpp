#include "rules.ih"

void Rules::warnNonViable()
{
    for 
    (
        auto begin = d_rules.begin(), iter = begin, end = d_rules.end();
            (iter = find_if(iter, end, nonViable)) != end;
                ++iter
    )
        wmsg << "Rule " << (iter - begin) << " (" << iter->source() << ": " <<
                    iter->lineNr() << ") can never be matched\n";
}
