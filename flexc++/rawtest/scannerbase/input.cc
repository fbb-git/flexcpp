#include "scannerbase.ih"

int ScannerBase::input()
{
    size_t ret;

    while (true)
    {
        ret = next();
        if (ret == s_rangeOfEOF)
            return -1;
        if (ret != s_rangeOfBOL)
            return d_char;
    }
}
