#include "scannerbase.ih"

// The queue may be empty or not, but we just read a char. that cannot be
// processed at this time, since the LA info comes first. So return d_char to
// the queue's front, followed by (in reverse order) the LA characters.
// then reduce the match-size and d_length by the LA length.

void ScannerBase::saveLookahead()
{
    d_deque.push_front(d_char);         // eventually reread the character,
                                        // ending the LA text.

    string const &tail = d_match.substr(d_LAlength);

                                        // push the LA text in front of the Q
    copy(tail.rbegin(), tail.rend(), front_inserter(d_deque));

    d_match.resize(d_LAlength);         // keep the prefix

    d_bol = false;                      // prevent BOL from being returned
    next();                             // get the next character to
                                        // handle by callExecute. 
}
