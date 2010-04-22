#include "scannerbase.ih"

void ScannerBase::updateCount(size_t rule)
{
    msg(2) << " Updating accept count for rule " << rule << '\n';

    Accept &accept = d_accept[rule];

    if (d_nextState < 0 || d_state < d_nextState)   // only back- or current 
        return;                                     // transitions result in
                                                    // updates

    if (accept.length == -1)                        // not yet initialized
    {
        accept = {d_match.length(), d_match.length()};
        return;
    }

    size_t curLen =  d_match.length();
    accept.length += curLen - accept.acceptLength;
    accept.acceptLength = curLen;

    msg(2) << "Update  accept length for rule " << rule << ": " <<
               accept.length << '\n';

}
