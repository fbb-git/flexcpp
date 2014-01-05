#include "flexc++.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        // options to set filenames

        // options setting filenames
        {Options::baseclassHeaderSpec(),      'b'}, // Options members also
        {Options::classHeaderSpec(),          'c'}, // used by Options::
        {Options::implementationHeaderSpec(), 'i'}, // setAccessorVariables()
        {Options::lexSourceSpec(),            'l'},
        {"target-directory",                  Arg::Required},
        {"filenames",                         'f'},
                                        
        // skeleton options             
        {"skeleton-directory",          'S'},
        {"baseclass-skeleton",          'B'},
        {"class-skeleton",              'C'},
        {"implementation-skeleton",     'I'},
        {"lex-skeleton",                'L'},

        // options preventing overwriting
        {"no-baseclass-header",         Arg::None},
        {"no-lex-source",               Arg::None},

        {"namespace",                   'n'},

        {"class-name",                  Arg::Required},
        {"lex-function-name",           Arg::Required},
        {"no-lines",                    Arg::None},

        {"help",                        'h'},
        {"usage",                       'h'},
        {"version",                     'v'},

        {"case-insensitive",            Arg::None},
        {"debug",                       'd'},
        {"construction",                'K'}, 
        {"matched-rules",               'R'},
        {"max-depth",                   'm'},
        {"print-tokens",                't'},
        {"own-tokens",                  'T'},
        {"show-filenames",              'F'},
        {"verbose",                     'V'},
        {"regex-calls",                 Arg::None},
    };

    auto longEnd = longOptions +
                                sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("b:B:c:C:df:Fhi:I:Kl:L:m:n:RS:TtvV",
                    longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, version, 1);

    DFA::setVerbose(arg.option('V'));

    States states;

    Rules rules(states);


    Parser parser(rules, states);
//parser.setDebug(true);
        parser.parse();
        parser.cleanup();

    Ranges ranges(states);
        ranges.determineSubsets();
        ranges.finalizeStates();

    DFAs dfas(rules, states, ranges);
        dfas.build();

    rules.warnNonViable();

    Generator generator(rules, ranges, dfas);
        generator.construction(states);
        generator.lexSource();
        generator.baseclassHeader();
        generator.classHeader();
        generator.implementationHeader();
}
catch (int x)
{
    return Arg::instance().option("hv") ? 0 : x;
}
catch(std::exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "[Panic] Unknown exception thrown." << '\n';
    return 1;
}
