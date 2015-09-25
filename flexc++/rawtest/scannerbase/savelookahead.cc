#include "scannerbase.ih"

    // d_ruleIndex holds the index of the matched rule
void ScannerBase::saveLookahead()
{
    Accept &accept = d_accept[d_ruleIndex];

    if (accept.headSize == -1)      // nothing to save
        return;

    retain(accept.headSize);

    msg(1) << "LA size = " << accept.headSize << ": match = " << d_match <<
            '\n';

    d_bol = false;                      // prevent BOL from being returned
}
