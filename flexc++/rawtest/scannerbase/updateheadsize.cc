#include "scannerbase.hh"

void ScannerBase::updateHeadSize()
{
    Accept &accept = acceptRecord();

    accept.headSize = accept.lastMatchSize;
    accept.lastMatchSize = d_match.length();
}
