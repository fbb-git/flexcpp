#ifndef _SCANNER_H_
#define _SCANNER_H_

#include "../scannerbase/scannerbase.h"

class Scanner: public ScannerBase
{
    public:
        Scanner();
        int lex();
    private:
        int execute(bool *cycle);
};

#endif



