#include "fstreaminfo.ih"

void FStreamInfo::checkStream() const
{
    if (!*d_in)
        lineMsg() << "cannot read `" << d_name << '\'' << fatal;
}
