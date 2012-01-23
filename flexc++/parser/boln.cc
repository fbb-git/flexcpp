#include "parser.ih"

spSemUnion Parser::boln()
{
    if (d_tokenCount == 1)      
        d_boln = true;
    else
    { 
        if (not d_warnCarets)
            wmsg << "`^' inside regex loses its special meaning" << endl;
        d_warnCarets = true;
    }        

    spSemUnion ret(rawText(d_warnCarets ? "^" : ""));

    return ret;
}
