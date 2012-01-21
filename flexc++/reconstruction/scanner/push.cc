#include "scanner.ih"

void Scanner::push(StartCondition__ next)
{
    d_scStack.push(next);
    begin(next);
    cout << "           ENTERING CONDITION " << (int)next << '\n';
}
