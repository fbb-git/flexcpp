#include "scannerbase.ih"

void ScannerBase::updateAcceptCounts()
{
    for 
    (
        auto begin = s_accept + d_dfa[d_state][s_acceptIdx],
             end = s_accept + d_dfa[d_state][s_acceptIdx + 1];
                begin != end;
                    ++begin
    )
        updateCount(*begin);
}


