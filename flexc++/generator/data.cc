#include "generator.ih"

Generator::Map Generator::s_insert =
{
    // $insert-key              function called
    {"DFAbases",                &Generator::DFAbases},
    {"DFAs",                    &Generator::dfas},
    {"RFs",                     &Generator::rfs},
    {"actions",                 &Generator::actions},
    {"baseclass_h",             &Generator::baseClassH},
    {"baseIncludes",            &Generator::baseIncludes},
    {"caseCheck",               &Generator::caseCheck},
    {"classHead",               &Generator::classHead},
    {"class_h",                 &Generator::classH},
    {"class_ih",                &Generator::classIH},
    {"inputInterface",          &Generator::inputInterface},
    {"inputImplementation",     &Generator::inputImplementation},
    {"debug",                   &Generator::debug},
    {"debugDecl",               &Generator::debugDecl},
    {"debugFunctions",          &Generator::debugFunctions},
    {"declarations",            &Generator::declarations},
    {"inlineLexFunction",       &Generator::inlineLexFunction},
    {"interactiveDecl",         &Generator::interactiveDecl},
    {"interactiveInit",         &Generator::interactiveInit},
    {"interactiveLex",          &Generator::interactiveLex},
    {"lexFunctionDecl",         &Generator::lexFunctionDecl},
    {"namespace-close",         &Generator::namespaceClose},    
    {"namespace-open",          &Generator::namespaceOpen},
    {"namespace-use",           &Generator::namespaceUse},
    {"print",                   &Generator::print},
    {"ranges",                  &Generator::ranges},
    {"scannerConstructors",     &Generator::scannerConstructors},
    {"startCondNames",          &Generator::startCondNames},
    {"sstream",                 &Generator::insertSstream},
};

char const *Generator::s_baseFlag = "\\@";
size_t const Generator::s_baseFlagSize = 2; // backslash and @

char const *Generator::s_namespaceBaseFlag = "\\@$";
size_t const Generator::s_namespaceBaseFlagSize = 3; // backslash, $ and @

string Generator::s_matchedTextFunction = "d_scanner.YYText()";
string Generator::s_scannerTokenFunction = "d_scanner.yylex()";


