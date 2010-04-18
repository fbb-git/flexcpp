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
    {
        size_t *count = d_accept + begin->rule;

        if (*count == 0)        // Rule 0, for inheriting an non-inheriting
            ++*count;           //  accept states

        if (begin->type == 'I' && d_state == d_nextState)
            ++*count;
    }
}
