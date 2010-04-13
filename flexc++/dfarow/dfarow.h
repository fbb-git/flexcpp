#ifndef INCLUDED_DFAROW_
#define INCLUDED_DFAROW_

#include <unordered_map>

class DFARow
{
    size_t d_final;     // matched rule when this state cannot continue
    std::unordered_map<size_t, size_t> d_transit;
    
    public:
        DFARow();

    private:
};
        
#endif
