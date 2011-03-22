#include "parser.ih"

namespace{
    char const *symbol[] = 
    {
        "EXCL_START_CONDITION",
        "INCL_START_CONDITION",
        "NAME",
        "SECTION_DELIMITER",
        "BASECLASSHEADER",
        "CLASSHEADER",
        "CLASSNAME",
        "DEBUG",
        "DEBUG_STEPS",
        "IMPLEMENTATIONHEADER",
        "INTERACTIVE",
        "LEXFUNCTIONNAME",
        "LEXSOURCE",
        "NAMESPACE",
        "OPTION_DIRECTIVE",
        "SKELETON_DIRECTORY",
        "BLOCK",
        "WS",
        "PREDEFINED_CLASS",
        "CC_PLUS",
        "CC_MINUS",
        "CHARACTER",
        "DECIMAL",
        "CC_NEGATED",
        "CC_START",
        "ESCAPE_SEQUENCE",
        "STRING",
        "EOF_PATTERN",
    };
}

int Parser::lex()
{
    print();
    ++d_patternTokenCount;
//    return d_scanner.pLex();

    int token = d_scanner.pLex();
    cout << "Token: " << token << ": ";
    if (isprint(token))
        cout << "char `" << static_cast<char>(token) << '\'';
    else if (token >= 0x100)
        cout << "symbol `" << symbol[token - 257] << '\'';

    cout << '\n';

    return token;
}

