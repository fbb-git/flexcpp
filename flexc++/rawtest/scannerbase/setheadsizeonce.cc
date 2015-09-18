#include "scannerbase.hh"

void ScannerBase::setHeadSizeOnce()
{
    Accept &accept = acceptRecord();

    msg(1) << "Rule " << acceptRule() << ": accept length at " << 
                d_state << ": " << accept.headSize;
                
    if (accept.headSize == -1)
        accept.headSize = d_match.length();

    msg(1) << " updated to " << accept.headSize << '\n';
}
