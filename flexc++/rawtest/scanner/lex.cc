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

        if (transition())
        {
            charToMatchBuffer();
            // updateLookahead();

            if (not interactiveReturn())
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
            if (atBOL())
                continue;

            if (atEOF())
            {
                if (not streamPopped())
                    throw -1;
                continue;
            }

            reRead();

            if (endOfRule())
            {
                bool done = true;
                int ret = execute(&done);
                reset();        // reset the dfa, clear match and acceptcounts
                if (done)
                    return ret;
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

