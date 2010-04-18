#ifndef _SCANNER_H_
#define _SCANNER_H_

// #include <fstream>
// #include <string>

#include "../scannerbase/scannerbase.h"

class Scanner: public ScannerBase
{
    public:
        Scanner();
        int lex();
};

#endif



