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

cout << "       POP-SC: RETURNING TO CONDITION " << 
                (d_scStack.empty() ? 0 : (int)d_scStack.top()) << '\n';

    return token;
}
