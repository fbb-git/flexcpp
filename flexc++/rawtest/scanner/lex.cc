#include "scanner.hh"

#include <iostream>

int Scanner::lex()
try
{
    while (true)
    {
        lookup();           // next: return BOL or get char.
                            // return EOF or set BOL, or return the char-range
                            // lookup: determine next state

        handleAcceptState();

        if (transition())
        {
            charToMatchBuffer();

            // updateAcceptCounts();

            if (not interactiveRuleMatched())
                nextState();
            else
            {
                bool done = true;
                int ret = execute(&done);
                reset();        // reset the dfa, clear match and acceptcounts
                if (done)
                    return ret;
            }
        }
        else
        {
            reRead();

            if (ruleMatched())
            {
                bool done = true;
                int ret = execute(&done);
                reset();        // reset the dfa, clear match and acceptcounts
                if (done)
                    return ret;
            }
            else if (atBOL())
                continue;
            else if (atEOF())
            {
                if (not streamPopped())
                    throw -1;
                continue;
            }
            else
            {
                input();
                notHandledChar();
                reset();
            }
        }
    }
}
catch (int ret)
{
    return ret;
}

