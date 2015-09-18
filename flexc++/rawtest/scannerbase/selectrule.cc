#include "scannerbase.hh"

int ScannerBase::selectRule() const
{
    size_t begin = d_dfa[d_state][s_finalIdx];
    size_t end = d_dfa[d_state][s_finalIdx + 1];

    if (begin == end)                       // ret -1 if not a FINAL state
        return -1;

    msg(2) << "     selectRule: init to rule -1, length: -1\n";

    pair<size_t, int> ret = {~0, -1};       // store rule/length

    for                                     // visit the Accept structs of 
    (                                       // all rules matched at this point
        int matchLength = d_match.length();
            begin != end;
                ++begin
    )
    {
        size_t rule = s_final[begin];

        Accept const &inspect = d_accept[rule];

        msg(2) << "     selectRule: inspect rule " << rule << 
                  ", length: " << inspect.headSize << '\n';

        int length =                            // if the current rule has no
            inspect.headSize == -1 ?            // LA operator, then use the 
                matchLength                     // match length
            :
                inspect.headSize;

        if 
        (
            length > ret.second                 // longer match or equal match
            ||                                  // and earlier rule, then use
            (                                   // that rule
                length == ret.second
                && 
                rule < ret.first
            )     
        )
            ret = {rule, length};

        msg(2) << "     selectRule: next rule " << ret.first << 
                  ", length: " << ret.second << '\n';
    }

    msg(1) << "     selectRule matched rule " << ret.first << ", length " << 
                                 ret.second << '\n';
    return ret.first;
}



