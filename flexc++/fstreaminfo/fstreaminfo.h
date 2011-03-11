#ifndef INCLUDED_FSTREAMINFO_
#define INCLUDED_FSTREAMINFO_

#include <iosfwd>

class FStreamInfo;

#include "../scanner/scannerbase.h"

class FStreamInfo: public StreamSwitching::StreamInfo
{
    static size_t s_inclusionDepth;

    enum LineNumbering
    {
        RESET,
        CONTINUE
    };
    LineNumbering d_lineNumbering;

    public:
        FStreamInfo();
        FStreamInfo(std::string const &name);
        FStreamInfo(std::string const &nameExpansion, 
                    std::string const &name);

        void resume(FStreamInfo const &streamInfo, size_t lineno);
        void connect(ScannerTemplate<FStreamInfo>::StreamAdapter *ptr);

    private:
        void checkStream() const;
};

inline FStreamInfo::FStreamInfo()
:
    d_lineNumbering(RESET)
{}

#endif


