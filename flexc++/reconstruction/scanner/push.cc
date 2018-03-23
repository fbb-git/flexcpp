#include "scanner.ih"

void Scanner::push(StartCondition_ next)
{
    d_scStack.push(next);
    begin(next);
    cout << "           ENTERING CONDITION " << (int)next << '\n';
}
