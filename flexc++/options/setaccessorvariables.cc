#include "options.ih"

void Options::setAccessorVariables()
{
    Arg &arg = Arg::instance();

    d_debug = d_debug || arg.option('d');   // debug facility requested

    if (d_debug)
        d_matchedRules = false;             // as debug implies -R

    d_print = d_print || arg.option('t');

    if (d_className.empty())
        d_className = s_defaultClassName;

    if (d_lexFunctionName.empty())
        d_lexFunctionName = s_defaultLexFunctionName;

    arg.option(&d_nameSpace, 'n');  // -n overrules %namespace spec in lexer

    string value;
    d_maxDepth = arg.option(&value, 'm') ? 
                    A2x(value).to<size_t>() 
                : 
                    MAX_DEPTH;
        
    // Skeletons
    if (!arg.option(&d_skeletonDirectory, 'S') && d_skeletonDirectory.empty())
        d_skeletonDirectory = s_defaultSkeletonDirectory;

    if (!arg.option(&d_baseClassSkeleton, 'B'))
        d_baseClassSkeleton      = d_skeletonDirectory + FLEXCPPBASE_H;

    if (!arg.option(&d_classSkeleton, 'C'))
        d_classSkeleton          = d_skeletonDirectory + FLEXCPP_H;

    if (!arg.option(&d_implementationSkeleton, 'I'))
        d_implementationSkeleton = d_skeletonDirectory + FLEXCPP_IH;

    if (!arg.option(&d_lexSkeleton, 'L'))
        d_lexSkeleton            = d_skeletonDirectory + FLEXCPP_CC;

//    if (arg.option(0, "interactive")) // does not overwrite %option when no
//        d_interactive = true;         // --interactive is supplied

    // Paths

    bool targetDirOption = arg.option(&d_targetDirectory, "target-directory");

    if (d_targetDirectory.length() && *d_targetDirectory.rbegin() != '/')
        d_targetDirectory += '/';

    arg.option(&d_filenames, 'f');  // -f overrules %filenames spec in lexer

    string filenames = d_filenames;
    if (filenames.empty())
        filenames = d_className;

    if (!targetDirOption && d_targetDirectory.empty())
        d_targetDirectory = s_defaultTargetDirectory;

    if (d_arg.option('K'))
        d_constructionPath = d_targetDirectory + d_arg[0] + ".output";

    setPath(&d_classHeaderPath, 'c', targetDirOption, "class-header", 
            filenames, ".h");

    setPath(&d_baseClassHeaderPath, 'b', targetDirOption, "base-class-header", 
            filenames, "base.h");

    setPath(&d_implementationHeaderPath, 'i', targetDirOption, 
            "implementation-header", filenames, ".ih");

    setPath(&d_lexSourcePath, 'l', targetDirOption, 
            "lex-source", String::lc(d_lexFunctionName), ".cc");
}
