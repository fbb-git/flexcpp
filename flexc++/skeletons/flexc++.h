#ifndef \@_H_INCLUDED_
#define \@_H_INCLUDED_

$insert baseclass.h

$insert namespace-open

class \@: public \@Base
{
    public:
        \@() = default;
        \@(std::istream &iStream);

$insert 8 lexFunctionDecl

    private:
        int executeAction(int ruleNr);
        int lex__();
        int executeAction__(int ruleNr);
};

inline \@::\@(std::istream &iStream)
:
    \@Base(iStream)
{}

$insert inlineLexFunction

inline int \@::executeAction(int ruleNr)
{
    return executeAction__(ruleNr);
}

$insert namespace-close

#endif // \@_H_INCLUDED_
