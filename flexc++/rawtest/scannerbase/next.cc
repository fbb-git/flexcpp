#include "scannerbase.ih"

size_t ScannerBase::next()
{
    int ret;

    if (d_bol)                  // d_bol is set if the previously returned
    {                           // character was '\n' and s_rangeOfBOL != 0
        d_bol = false;
        msg(2) << "next: BOL\n";
        return d_range = s_rangeOfBOL;
    }

    if (d_deque.empty())        // get the next input char, from the deque
        ret = cin.get();        // or from the input
    else
    {
        ret = d_deque.front();
        d_deque.pop_front();
    }

    if (ret == EOF)             // got EOF
    {
        msg(2) << "next: EOF\n";
        return d_range = s_rangeOfEOF;
    }

    if (ret == '\n' && s_rangeOfBOL != 0)   // on '\n' and BOL is used: set
        d_bol = true;                       // BOL as the next range to return

    d_char = ret;               // got something else: keep its value

    d_range = s_ranges[ret];    // and return its range nr.

    msg(2) << "\nGot ";
    if (isprint(d_char))
        msg(2) << '\'' << d_char << '\'';
    else
        msg(2) << setw(3) << 
                static_cast<size_t>(static_cast<unsigned char>(d_char));

    msg(2) << ", range = " << d_range << '\n';

    return d_range;
}


