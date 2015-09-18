#include "parser.hh"

namespace
{
    bool repeated;
    string eoln("<EOLN>");
}

void Parser::error(char const *msg)
{
    if (!d_doError)         // this allows functions to call ERROR and handle
    {                       // their own error message
        d_doError = true;
        return;
    }
        
    if (d_expect.empty())
    {
        if (not repeated)
            emsg << "unrecognized input (`" << d_matched << 
                         "') encountered" << endl;
        repeated = true;
    }
    else
    {
        string const *txt = &d_matched;
        if (*txt == "\n")
            txt = &::eoln;

        if (s_lastMsg != d_expect)
        {
            if (txt == &::eoln)
                emsg.setLineNr(d_scanner.lineNr());
            emsg << "at `" << *txt << "': " << d_expect << " expected." << endl;

            repeated = false;
        }
    }

    s_lastMsg = d_expect;
}
