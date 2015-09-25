#include "options.ih"

    // called by parser.cleanup()

void Options::setPathStrings()
{
    d_arg.option(&d_filenames, 'f');  // -f overrules %filenames spec in lexer

    string filenames = d_filenames;
    if (filenames.empty())
        filenames = d_className;

    setOptionPath(&d_baseClassHeader, 'b', filenames, "base.h", 
                                                baseclassHeaderSpec());

    setOptionPath(&d_classHeader, 'c', filenames, ".h", 
                                                classHeaderSpec());

    setOptionPath(&d_implementationHeader, 'i', filenames, ".ih",
                                                implementationHeaderSpec());

    setOptionPath(&d_lexSource, 'l', String::lc(d_lexFunctionName), ".cc",
                                                lexSourceSpec());
}
