#include "scanner.ih"


int Scanner::lex()
try
{
    reset();

    while (true)
    {
        nextState();

        if (!lookup(next()))        // no transition or unaccounted for BOL
            continue;               // proceed...

        updateAcceptCounts();
        
        if (confirmExecute())
        {
            reset();
            bool cycle = false;
            int ret = execute(&cycle);
            if (cycle)
                continue;
            return ret;
        }
    }
}
catch (int ret)
{
    return ret;
}

