#include "scanner.ih"

std::ostream &Scanner::lineMsg(int deltaLineNo) const
{
    Msg::setLine(lineno() + deltaLineNo);
    return FBB::lineMsg() << "(" << streamInfo().name() << ") ";
}
