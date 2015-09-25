#include "scanner.ih"

void Scanner::setLineTags(std::string const &filename) const
{
    string tag = filename + ", line";
    emsg.setLineTag(tag);
    wmsg.setLineTag(tag);
}
