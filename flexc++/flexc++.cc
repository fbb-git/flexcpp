#include "flexc++.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        // options to set filenames

        // options to set filenames
        {"baseclass-header",            'b'},
        {"class-header",                'c'},
        {"implementation-header",       'i'},
        {"lex-source",                  'l'},
                                        
        // skeleton options             
        {"skeleton-directory",          'S'},
        {"baseclass-skeleton",          'B'},
        {"class-skeleton",              'C'},
        {"implementation-skeleton",     'I'},
        {"lex-skeleton",                'L'},

        // options forcing overwriting
        {"force-class-header",          Arg::None},
        {"force-implementation-header", Arg::None},
        {"no-baseclass-header",         Arg::None},
        {"no-lex-source",               Arg::None},

        {"class-name",                  Arg::Required},
        {"lex-function-name",           Arg::Required},
        {"lines",                       Arg::None},
        {"no-lines",                    Arg::None},

        {"namespace",                   'n'},

        {"help",                        'h'},
        {"interactive",                 Arg::None},
        {"usage",                       'h'},
        {"version",                     'v'},

        {"debug",                       'd'},
        {"debug-steps",                 's'},
        {"construction",                'K'},
        {"print-tokens",                't'},
        {"show-filenames",              'F'},
        {"verbose",                     'V'},
    };

    auto longEnd = longOptions +
                                sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("b:B:c:C:dFhi:I:Kl:L:n:s::S:tvV",
                    longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, version, 1);

    States states;
    Rules rules(states);

    Parser parser(rules, states);
        parser.parse();

    if (Msg::errors())
        return 1;

//    Ranges ranges(states);
//        ranges.determineSubsets();
//        ranges.finalizeStates();
//
//    if (arg.option('V'))
//        cout << 
//            "RULES:\n"      <<
//            rules << "\n"
//            "RANGES:\n"     << 
//            ranges << "\n"
//            "STATES:\n"     <<
//            states << '\n';
//
//    DFAs dfas(rules, states, ranges);
//        dfas.build();
//
//        rules.warnNonViable();
//
//    Generator generator(rules, ranges, dfas);
//        generator.construction(states);
//        generator.lexSource();
//        generator.baseclassHeader();
//        generator.classHeader();
//        generator.implementationHeader();
//        generator.showFilenames();
}
catch (int x)
{
    return x;
}
catch (Errno const &error)
{
    cerr << error.what() << '\n';
    return error.which();
}
catch(std::exception const &exc)
{
    cerr << "std exception: " << exc.what() << '\n';
    return 1;
}
catch (...)
{
    cerr << "[Panic] Unexpected exception raised." << '\n';
    return 1;
}
