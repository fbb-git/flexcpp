#include "fstreaminfo.ih"

FStreamInfo::FStreamInfo(string const &nameExpansion, string const &name)
:
    StreamInfo(new istringstream(nameExpansion)),
    d_lineNumbering(CONTINUE)
{
    d_name = name;
    checkStream();
}

