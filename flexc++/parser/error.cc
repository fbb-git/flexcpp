#include "parser.ih"

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
        
    if (d_msg.empty())
    {
        if (not repeated)
            emsg << "unrecognized input (`" << d_scanner.match() << 
                         "') encountered" << endl;
        repeated = true;
    }
    else
    {
        string const *txt = &d_scanner.match();
        if (*txt == "\n")
            txt = &eoln;

        if (s_lastMsg != d_msg)
        {
            if (txt == &eoln)
                emsg.setLineNr(d_scanner.lineno() - 1);
            emsg << "at `" << *txt << "': " << d_msg << " expected." << endl;

            repeated = false;
        }
    }

    s_lastMsg = d_msg;
}
