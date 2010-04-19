#include "scanner.ih"

#include <iostream>

int Scanner::lex()
try
{
    reset();        // reset the dfa to state 0, clear match and acceptcounts

    while (true)
    {
        lookup(next());     // next: return BOL or get char.
                            // return EOF or set BOL, or return the char-range
                            // lookup: determine next state

        updateAcceptCounts();
        
        if (callExecute())  
        {
            bool done = true;
            int ret = execute(&done);
            if (done)
                return ret;
        }
        nextState();
    }
}
catch (int ret)
{
    return ret;
}

