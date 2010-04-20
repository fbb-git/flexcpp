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

        if (*count == 0)        // Rule 0, for inheriting and non-inheriting
            *count = d_match.length();      //  accept states
        else if (begin->type == 'I' && d_state == d_nextState)
            ++*count;

        msg(1) << "Update  accept count for rule " << begin->rule << ": " <<
                *count << '\n';
    }
}
