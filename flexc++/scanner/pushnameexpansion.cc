#include "scanner.ih"

void Scanner::pushNameExpansion()
{
    auto iter = d_nameExpansion.find(matched());

    if (iter == d_nameExpansion.end())
        fmsg << "Name expansion `" << matched() << "\' not found" << endl;

    push(iter->second);
}
