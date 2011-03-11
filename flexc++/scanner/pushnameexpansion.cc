#include "scanner.ih"

void Scanner::pushNameExpansion()
{
    auto iter = d_nameExpansion.find(d_match);

    if (iter == d_nameExpansion.end())
        fmsg << "Name expansion `" << d_match << "\' not found" << endl;

    pushStreamInfo(
        new StreamInfoType(iter->second, iter->first)
    );
}
