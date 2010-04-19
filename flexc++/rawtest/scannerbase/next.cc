#include "scannerbase.ih"

size_t ScannerBase::next()
{
    int ret;

    if (d_bol)                  // d_bol is set if the previously returned
    {                           // character was '\n' and s_rangeOfBOL != 0
        d_bol = false;
        return s_rangeOfBOL;
    }

    if (d_deque.empty())        // get the next input char, from the deque
        ret = cin.get();        // or from the input
    else
    {
        ret = d_deque.front();
        d_deque.pop_front();
    }

    if (ret == EOF)             // got EOF
        return s_rangeOfEOF;

    if (ret == '\n' && s_rangeOfBOL != 0)   // on '\n' and BOL is used: set
        d_bol = true;                       // BOL as the next range to return

    d_char = ret;               // got something else: keep its value

    ret = s_ranges[ret];        // and return its range nr.

    msg(1) << "Got '" << d_char << "', range = " << ret << endl;

    return ret;
}

