#include "generator.ih"

Generator::Map Generator::s_insert =
{
    {"DFAbases",           &Generator::DFAbases},
    {"DFAs",               &Generator::dfas},
    {"actions",            &Generator::actions},
    {"baseclass.h",        &Generator::baseClassH},
    {"class.h",            &Generator::classH},
    {"class.ih",           &Generator::classIH},
    {"debug",              &Generator::debug},
    {"debugDecl",          &Generator::debugDecl},
    {"debugFunctions",     &Generator::debugFunctions},
    {"debugIncludes",      &Generator::debugIncludes},
    {"debugInit",          &Generator::debugInit},
    {"debugStep",          &Generator::debugStep},
    {"declarations",       &Generator::declarations},
    {"finAcs",             &Generator::finAcs},
    {"ifStartsAtBOLelse",  &Generator::ifStartsAtBOLelse},
    {"ignoreBOLaction",    &Generator::ignoreBOLaction},
    {"ignoreBOLcall",      &Generator::ignoreBOLcall},
    {"ignoreBOLimpl",      &Generator::ignoreBOLimpl},
    {"inlineLexFunction",  &Generator::inlineLexFunction},
    {"inputMembers",       &Generator::inputMembers},
    {"lexFunctionDecl",    &Generator::lexFunctionDecl},
    {"namespace-close",    &Generator::namespaceClose},
    {"namespace-open",     &Generator::namespaceOpen},
    {"namespace-use",      &Generator::namespaceUse},
    {"ranges",             &Generator::ranges},
    {"rangeAtBOL",         &Generator::rangeAtBOL},
    {"startCondNames",     &Generator::startCondNames},
};

char const *Generator::s_baseFlag = "\\@";
size_t const Generator::s_baseFlagSize = 2; // backslash and @

string Generator::s_matchedTextFunction = "d_scanner.YYText()";
string Generator::s_scannerTokenFunction = "d_scanner.yylex()";


