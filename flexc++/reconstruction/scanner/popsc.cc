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

cout << "       POP-SC: RETURNING TO CONDITION " << 
                (d_scStack.empty() ? 0 : (int)d_scStack.top()) << '\n';

    return token;
}
