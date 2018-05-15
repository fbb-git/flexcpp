#include "scanner.ih"

bool Scanner::handleStdComment()
{
    if (d_inCharClass)
        return true;

    push(StartCondition_::comment);        
    return false;
}
