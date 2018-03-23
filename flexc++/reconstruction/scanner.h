// Generated by Flexc++ V0.8.3 on Sat, 21 Jan 2012 15:47:47 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "scannerbase.h"


class Scanner: public ScannerBase
{
    public:
        explicit Scanner(std::istream &in = std::cin, 
                    std::ostream &out = std::cout);
        
        Scanner(std::string const &infile, std::string const &outfile);

        // $insert lexFunctionDecl
        int lex();

    private:
        int lex_();
        int executeAction_(size_t ruleNr);

        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline Scanner::Scanner(std::istream &in, std::ostream &out)
:
    ScannerBase(in, out)
{}

inline Scanner::Scanner(std::string const &infile, std::string const &outfile)
:
    ScannerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex_();
}


#endif // Scanner_H_INCLUDED_

