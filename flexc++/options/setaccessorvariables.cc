#include "options.ih"

void Options::setAccessorVariables()
{
    Arg &arg = Arg::instance();

    if (d_className.empty())
        d_className = s_defaultClassName;

    if (d_lexFunctionName.empty())
        d_lexFunctionName = s_defaultLexFunctionName;

    arg.option(&d_nameSpace, 'n');  // -n overrules %namespace spec in lexer

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
    if (!arg.option(&d_baseClassHeaderPath, 'b')
            && d_baseClassHeaderPath.empty())
        d_baseClassHeaderPath = String::lc(d_className) + "base.h";

    if (!arg.option(&d_classHeaderPath, 'c') && d_classHeaderPath.empty())
        d_classHeaderPath = String::lc(d_className) + ".h";

    if (!arg.option(&d_implementationHeaderPath, 'i')
            && d_implementationHeaderPath.empty())
        d_implementationHeaderPath = String::lc(d_className) + ".ih";

    if (!arg.option(&d_lexSourcePath, 'l') && d_lexSourcePath.empty())
        d_lexSourcePath = String::lc(d_lexFunctionName) + ".cc";

    if (arg.option(0, "interactive")) // does not overwrite %option when no
        d_interactive = true;         // --interactive is supplied

    d_debugAll |= arg.option('d');         // debug facility requested

    if (arg.option(0, "lines"))             // --lines overrules 
        d_lines = true;                     // --no-lines
    else if (arg.option(0, "no-lines"))
        d_lines = false;

    string range;
    if (arg.option(&range, 's'))
    {
        if (range.empty())
        {
            d_beginStep = 0;
            d_endStep = ~0U;
        }
        else
        {
            size_t value;
            istringstream in(range);
            if (in >> value)
            {
                d_beginStep = value;
                in.ignore(1);
                if (in >> value)
                    d_endStep = value + 1;
            }
            else
                wmsg << "Option -s" << range << " ignored." << endl;
        }
    }
}
