#include "ranges.ih"

void Ranges::copyUsedRanges(std::shared_ptr<bool> &dest)
{
    dest.reset(
        static_cast<bool *>(
            memcpy(new bool[d_nRanges], d_usedRanges, 
                    d_nRanges * sizeof(bool)
            )
        )
    );
}
