#include "scannerbase.ih"

int ScannerBase::selectRule() const
{
cerr << "selectRule, d_state = " << d_state << "\n";

    size_t begin = d_dfa[d_state][s_finalIdx];
    size_t end = d_dfa[d_state][s_finalIdx + 1];

    if (begin == end)                       // ret -1 if not a FINAL state
        return -1;

    pair<size_t, int> ret = {~0, -1};       // store rule/length

    msg(2) << "     selectRule: init rule -1, length: -1\n";

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
                  ", length: " << inspect.length << '\n';

        int length =                            // if the current rule has no
            inspect.length == -1 ?              // LA operator, then use the 
                matchLength                     // match length
            :
                inspect.length;

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

    msg(2) << "     selectRule matched rule " << ret.first << ", length " << 
                                 ret.second << '\n';
    return ret.first;
}



