#include "scanner.ih"

bool Scanner::handleStdComment()
{
//    if (d_inCharClass)
//        return true;

    push(StartCondition__::comment);        
    return false;
}
