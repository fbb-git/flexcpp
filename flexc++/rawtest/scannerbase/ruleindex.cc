#include "scannerbase.ih"

int ScannerBase::ruleIndex() const
{
    vector<pair<int, size_t>> competitors;

    for 
    (
        int begin = d_dfa[d_state][s_finalIdx], 
           length = d_match.length(),
              end = d_dfa[d_state][s_finalIdx + 1];
        begin != end;
            ++begin
    )
    {
        int len = d_accept[begin].length;

        if (len == -1)
            len = length;

        competitors.push_back({-len, begin});
    }

    if (competitors.empty())
        return -1;
    
    sort(competitors.begin(), competitors.end());
    int rule = competitors.front().second;

    msg(1) << "matched rule " << rule << " with length " << 
                                        -competitors.front().first << '\n';
    return rule;
}


