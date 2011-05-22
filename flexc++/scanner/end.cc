#include "scanner.ih"

int Scanner::end(int token)
{
    if (d_fromCondition.size())         // no size at INITIAL
    {
        ScannerBase::begin(d_fromCondition.top());
        d_fromCondition.pop();
    }
    return token;
}
