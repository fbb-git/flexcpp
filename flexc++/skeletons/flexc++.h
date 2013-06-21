#ifndef \@$_H_INCLUDED_
#define \@$_H_INCLUDED_

$insert baseclass_h

$insert namespace-open

$insert classHead
        
$insert 8 lexFunctionDecl

    private:
        int lex__();
        int executeAction__(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts
};

$insert scannerConstructors

$insert inlineLexFunction

inline void \@::preCode() 
{
    // optionally replace by your own code
}

inline void \@::print() 
{
    print__();
}

$insert namespace-close

#endif // \@_H_INCLUDED_

