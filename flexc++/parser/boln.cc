#include "parser.ih"

Pattern Parser::boln()
{
    if (d_tokenCount <= 1)      
        d_boln = true;
    else
    { 
        if (not d_warnCarets)
            wmsg << "`^' inside regex loses its special meaning" << endl;
        d_warnCarets = true;
    }        

    return rawText(d_warnCarets ? "^" : "");
}
