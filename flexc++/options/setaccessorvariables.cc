#include "options.ih"

// called by the generator, possibly overruling directives by options

void Options::setAccessorVariables()
{
    Arg &arg = Arg::instance();

    d_debug = d_debug || arg.option('d');   // debug facility requested

    if (d_debug)
        d_matchedRules = false;             // as debug implies -R

    d_print = d_print || arg.option('t');

    if (d_arg.option(&d_className, "class-name"))
        s_warnOptions.insert("class-name");

    if (d_className.empty())
        d_className = s_defaultClassName;

    if (d_lexFunctionName.empty())
        d_lexFunctionName = s_defaultLexFunctionName;

    if (d_startConditionName.empty())       // not a program option
        d_startConditionName = s_defaultStartConditionName;

    string value;
    d_maxDepth = arg.option(&value, 'm') ? 
                    stoul(value)
                : 
                    MAX_DEPTH;

    if (arg.option(&d_nameSpace, 'n'))
    {
        s_warnOptions.insert("namespace");
        setNameSpaceIdentifier();
    }

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

    // Paths

    arg.option(&d_targetDirectory, "target-directory");

    if (d_targetDirectory.length() && *d_targetDirectory.rbegin() != '/')
        d_targetDirectory += '/';

    if (d_arg.option('K'))
        d_constructionPath = d_targetDirectory + d_arg[0] + ".output";
}






