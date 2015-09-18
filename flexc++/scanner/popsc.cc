#include "scanner.hh"

int Scanner::popSc(int token)
{
    if (not d_scStack.empty())
        d_scStack.pop();
        
    begin(d_scStack.empty() ? 
                StartCondition__::INITIAL
            :
                d_scStack.top()
    );

    return token;
}
