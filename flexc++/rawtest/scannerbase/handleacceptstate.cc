#include "scannerbase.ih"

void ScannerBase::handleAcceptState()
{
    switch (acceptStateType())
    {
        default:     // not an accept state
        break;

        case 'F':     // Fixed Head Accept State
            setHeadSizeOnce();
        break;

        case 'V':    // Variable Head Accept State
            updateHeadSize();
        break;
    }
}
