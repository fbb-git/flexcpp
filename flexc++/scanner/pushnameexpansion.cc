#include "scanner.ih"

void Scanner::pushNameExpansion()
{
    auto iter = d_nameExpansion.find(d_match);

    if (iter == d_nameExpansion.end())
        lineMsg() << "Name expansion `" << d_match << "\' not found" << fatal;

    pushStreamInfo(
        new StreamInfoType(iter->second, iter->first)
    );
}
