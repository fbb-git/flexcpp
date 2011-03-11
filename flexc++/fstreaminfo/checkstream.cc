#include "fstreaminfo.ih"

void FStreamInfo::checkStream() const
{
    if (!*d_in)
        fmsg << "cannot read `" << d_name << '\'' << endl;
}
