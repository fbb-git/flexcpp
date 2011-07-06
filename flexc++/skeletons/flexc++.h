#ifndef \@_H_INCLUDED_
#define \@_H_INCLUDED_

$insert baseclass_h

$insert namespace-open

class \@: public \@Base
{
    public:
        explicit \@(std::istream &in = std::cin, 
                    std::ostream &out = std::cout);
        
        \@(std::string const &infile, std::string const &outfile);

$insert 8 lexFunctionDecl

    private:
        int lex__();
        int executeAction__(size_t ruleNr);

        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

inline void \@::preCode() 
{
    // optionally replace by your own code
}

inline \@::\@(std::string const &infile, std::string const &outfile)
:
    \@Base(infile, outfile)
{}

$insert inlineLexFunction

$insert namespace-close

#endif // \@_H_INCLUDED_

