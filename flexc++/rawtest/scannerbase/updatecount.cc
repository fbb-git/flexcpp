#include "scannerbase.ih"

void ScannerBase::updateCount(size_t rule)
{
    Accept &accept = d_accept[rule];
    size_t curLen =  d_match.length();

    if (accept.LAsize == -1)                        // not yet initialized
    {
        if (curLen == 0)
        {
            msg(2) << " Not yet initializing due to zero matchlen\n";
            return;
        }
            
        accept = {0, curLen};
        msg(1) << " LA rule " << rule << 
                    " accept 0, curlen: " << curLen << " (init)\n";
        return;
    }

//    if (d_nextState < 0 || d_state < d_nextState)   // only step backs
//    {                                               // result in
//        accept.acceptLength = curLen;               // updates
//        msg(2) << " Updating acceptlen at step forward to " << curLen << '\n';
//        return;
//    }

    accept.LAsize += curLen - accept.lastMatchSize;

    msg(1) << " LA rule " << rule << 
                " accept " << accept.LAsize << ", curlen: " << curLen << 
                " last len: " << accept.lastMatchSize << "\n\n";

    accept.lastMatchSize = curLen;
}

