#include "scanner.ih"

#include <iostream>

int Scanner::lex()
try
{
    while (true)
    {
        lookup();           // next: return BOL or get char.
                            // return EOF or set BOL, or return the char-range
                            // lookup: determine next state

        updateAcceptCounts();
        
        if (callExecute())    
        {
            bool done = true;
            int ret = execute(&done);
            reset();        // reset the dfa, clear match and acceptcounts
            if (done)
                return ret;
            continue;       // restart if there's no action or if the action
                            // doesn't return
        }

        nextState();
    }
}
catch (int ret)
{
    return ret;
}

