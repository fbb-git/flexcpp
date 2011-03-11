#include "generator.ih"

Generator::Map Generator::s_insert =
{
    {"namespace-open",     &Generator::namespaceOpen},
    {"namespace-close",    &Generator::namespaceClose},
    {"startCondNames",     &Generator::startCondNames},
    {"baseclass.h",        &Generator::baseClassH},
    {"lexFunctionDecl",    &Generator::lexFunctionDecl},
    {"inlineLexFunction",  &Generator::inlineLexFunction},
    {"namespace-use",      &Generator::namespaceUse},
    {"class.h",            &Generator::classH},
    {"class.ih",           &Generator::classIH},
    {"ranges",             &Generator::ranges},
    {"DFAs",               &Generator::dfas},
    {"finAcs",             &Generator::finAcs},
    {"DFAbases",           &Generator::DFAbases},
    {"declarations",       &Generator::declarations},


//    {"actioncases",         &Generator::actionCases},
//    {"debug",               &Generator::debug},
//    {"debugdecl",           &Generator::debugDecl},
//    {"debuginit",           &Generator::debugInit},
//    {"debugfunctions",      &Generator::debugFunctions},
//    {"debugincludes",       &Generator::debugIncludes},
//    {"debuglookup",         &Generator::debugLookup},
//    {"errorverbose",        &Generator::errorVerbose},
//    {"print",               &Generator::print},
//    {"threading",           &Generator::threading},
//    {"tokens",              &Generator::tokens},
};

char const *Generator::s_baseFlag = "\\@";
size_t const Generator::s_baseFlagSize = 2; // backslash and @

string Generator::s_matchedTextFunction = "d_scanner.YYText()";
string Generator::s_scannerTokenFunction = "d_scanner.yylex()";


