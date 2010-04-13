#include "fstreaminfo.ih"

size_t FStreamInfo::s_inclusionDepth = 0;

void FStreamInfo::connect(ScannerTemplate<FStreamInfo>::StreamAdapter *ptr)
{
    if (++s_inclusionDepth == 10)
        lineMsg() << "max. file inclusion depth exceeded for `" << d_name <<
                    '\'' << fatal;

    ptr->in = d_in;
    if (d_lineNumbering == RESET)
        ptr->lineno = 1;
}

