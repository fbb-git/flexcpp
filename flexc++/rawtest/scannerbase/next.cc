#include "scannerbase.ih"

size_t ScannerBase::next()
{
    int ret;
    
    if (d_bol)                  // d_bol is set if the previously returned
    {                           // character was '\n' and s_rangeOfBOL != 0
        d_bol = false;
        return s_rangeOfBOL;
    }

    if (d_queue.empty())        // get the next input char, from the queue
        ret = cin.get();        // or from the input
    else
    {
        ret = d_queue.front();
        d_queue.pop();
    }
    
    if (ret == EOF)             // got EOF
        return s_rangeOfEOF;

    if (ret == '\n' && s_rangeOfBOL != 0)   // on '\n' and BOL is used: set
        d_bol = true;                       // BOL as the next range to return

    d_char = ret;               // got something else: keep its value
    return s_ranges[ret];       // and return its range nr.
}
