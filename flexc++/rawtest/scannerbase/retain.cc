#include "scannerbase.hh"

void ScannerBase::retain(size_t nChars)
{
    if (d_match.size() <= nChars)
        return;

    string const &tail = d_match.substr(nChars);

                                        // push the LA text in front of the Q
    copy(tail.rbegin(), tail.rend(), front_inserter(d_deque));

    d_match.resize(nChars);             // keep the prefix
}
