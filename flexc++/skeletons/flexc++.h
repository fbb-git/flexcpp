#ifndef \@_H_INCLUDED_
#define \@_H_INCLUDED_

$insert baseclass_h

$insert namespace-open

class \@: public \@Base
{
    public:
        \@(std::string const &filename);

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

inline \@::\@(std::string const &filename)
:
    \@Base(filename)
{}

$insert inlineLexFunction

$insert namespace-close

#endif // \@_H_INCLUDED_

