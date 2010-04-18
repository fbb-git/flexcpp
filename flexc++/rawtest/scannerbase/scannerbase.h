#ifndef INCLUDED_SCANNERBASE_
#define INCLUDED_SCANNERBASE_

#include <string>
#include <unordered_map>
#include <queue>

class ScannerBase
{
    std::string d_match;
    std::queue<char> d_queue;
    bool d_bol;
    char d_char;        // most recently received character,
    size_t d_state;

#include "../../tmp/bin/DECLARE"

    public:
        ScannerBase();
    protected:
        size_t next();
        bool lookup(size_t range);

    private:
        void cleanup();

};
        
#endif
