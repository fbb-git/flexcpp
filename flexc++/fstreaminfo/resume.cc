#include "fstreaminfo.ih"

void FStreamInfo::resume(FStreamInfo const &streamInfo, size_t lineno)
{
    string tag = name() + ", line";

    --s_inclusionDepth;
    emsg.setLineTag(tag);
    wmsg.setLineTag(tag);
}
