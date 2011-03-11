// Recompile this file if the skeleton locations in INSTALL.im change

#include "options.ih"
#include "SKEL"

char Options::s_defaultSkeletonDirectory[]       = _Skel_;

char Options::s_defaultBaseclassSkeleton[]       = _Skel_ FLEXCPPBASE_H;
char Options::s_defaultClassSkeleton[]           = _Skel_ FLEXCPP_H;
char Options::s_defaultImplementationSkeleton[]  = _Skel_ FLEXCPP_IH;
char Options::s_defaultLexfunSkeleton[]          = _Skel_ FLEXCPP_CC;

char Options::s_defaultLexFunctionName[]        = "yylex";
char Options::s_defaultClassName[]              = "Scanner";

Options Options::s_options;
