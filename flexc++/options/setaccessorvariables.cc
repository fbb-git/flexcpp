#include "options.ih"

void Options::setAccessorVariables()
{
    Arg &arg = Arg::instance();

    if (d_className.empty())
        d_className = s_defaultClassName;

    if (d_lexFunctionName.empty())
        d_lexFunctionName = s_defaultLexFunctionName;

    arg.option(&d_nameSpace, 'n');  // -n overrules %namespace spec in lexer

    if (d_streamInfoClassName.empty())
        d_streamInfoClassName = s_defaultStreamInfoClassName;

    // Skeletons
    string skeletondir;
    if (arg.option(&skeletondir, 'S'))
        d_skeletonDirectory = skeletondir;

    if (d_skeletonDirectory.empty())
        d_skeletonDirectory = s_defaultSkeletonDirectory;

    if (!arg.option(&d_baseClassSkeleton, 'B'))
        d_baseClassSkeleton      = d_skeletonDirectory + "/scannerbase.h";

    if (!arg.option(&d_classSkeleton, 'C'))
        d_classSkeleton          = d_skeletonDirectory + "/scanner.h";

    if (!arg.option(&d_implementationSkeleton, 'I'))
        d_implementationSkeleton = d_skeletonDirectory + "/scanner.ih";

    if (!arg.option(&d_lexSkeleton, 'L'))
        d_lexSkeleton            = d_skeletonDirectory + "/lex.cc";

    // Paths
    if (!arg.option(&d_baseClassHeaderPath, 'b')
            && d_baseClassHeaderPath.empty())
        d_baseClassHeaderPath = String::lc(d_className) + "base.h";

    if (!arg.option(&d_classHeaderPath, 'c') && d_classHeaderPath.empty())
        d_classHeaderPath = String::lc(d_className) + ".h";

    if (!arg.option(&d_implementationHeaderPath, 'i')
            && d_implementationHeaderPath.empty())
        d_implementationHeaderPath = String::lc(d_className) + ".ih";

    if (!arg.option(&d_lexSourcePath, 'i') && d_lexSourcePath.empty())
        d_lexSourcePath = String::lc(d_lexFunctionName) + ".cc";

    if (arg.option(0, "interactive")) // does not overwrite %option when no
        d_interactive = true;         // --interactive is supplied
}
