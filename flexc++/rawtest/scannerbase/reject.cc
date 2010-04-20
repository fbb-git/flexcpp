#include "scannerbase.ih"

void ScannerBase::reject()
{
    d_rejected = true;
    d_deque.push_front(d_char);         // eventually reread the character,
    retain(0);
    d_bol = false;
    next();
}
