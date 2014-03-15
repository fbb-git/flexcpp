#include "dfas.ih"

void DFAs::warnNonViable() const
{
    set<size_t> nonViable(
                    Iterator<size_t>(0), 
                    Iterator<size_t>(d_rules.nUserRules())
                );

    for (auto &dfaInfo: d_dfa)
    {
        if (isdigit(dfaInfo.first[0]))
            break;

        removeRules(*dfaInfo.second, nonViable);
    }

    for(size_t rule: nonViable)
        wmsg << "Rule " << rule << " (" << d_rules[rule].source() << ": " <<
                    d_rules[rule].lineNr() << ") can never be matched" << endl;
}
