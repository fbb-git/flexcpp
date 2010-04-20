#include "scannerbase.ih"

// The queue may be empty or not, but we just read a char. that cannot be
// processed at this time, since the LA info comes first. So return d_char to
// the queue's front, followed by (in reverse order) the LA characters.
// then reduce the match-size and d_length by the LA length.

void ScannerBase::saveLookahead()
{
    d_deque.push_front(d_char);         

    size_t beginTail = d_length + d_lookaheadLength;
    string const &tail = d_match.substr(beginTail);

    copy(tail.rbegin(), tail.rend(), front_inserter(d_deque));

    d_match.resize(beginTail);
    d_length -= d_lookaheadLength;
}
