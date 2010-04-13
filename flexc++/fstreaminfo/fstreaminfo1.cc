#include "fstreaminfo.ih"

FStreamInfo::FStreamInfo(std::string const &name)
:
    StreamInfo(name.c_str()),
    d_lineNumbering(RESET)
{
    checkStream();
}

