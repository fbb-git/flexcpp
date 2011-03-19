#ifndef \@_H_INCLUDED_
#define \@_H_INCLUDED_

$insert baseclass_h

$insert namespace-open

class \@: public \@Base
{
    public:
        \@() = default;
        explicit \@(std::istream &iStream, std::ostream &out = std::cout);

$insert 8 lexFunctionDecl

    private:
        int lex__();
        int executeAction__(int ruleNr);

        void preCode__();   // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

inline void Scanner::preCode__()    // optionally replace by your own code
{}

inline \@::\@(std::istream &iStream, std::ostream &oStream)
:
    \@Base(iStream, oStream)
{}

$insert inlineLexFunction

$insert namespace-close

#endif // \@_H_INCLUDED_
