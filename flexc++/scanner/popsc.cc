#include "scanner.ih"

int Scanner::popSc(int token)
{
    if (not d_scStack.empty())
        d_scStack.pop();
        
    begin(d_scStack.empty() ? 
                StartCondition_::INITIAL
            :
                d_scStack.top()
    );

    return token;
}
