#include "scannerbase.ih"

bool ScannerBase::rejectReturn()
{
    if (d_rejected && ruleIndex() == d_lastRule)
    {
        d_rejected = false;
        return true;
    }

    return false;
}
