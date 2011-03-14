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
        {"force-implementation-header", Arg::None},
        {"force-class-header",          Arg::None},
        {"no-baseclass-header",         Arg::None},
        {"no-lex-member",               Arg::None},


        {"class-name",                  Arg::Required},
        {"lex-function-name",           Arg::Required},
     // {"show-filenames"               Arg::None},
     // {"nolines",                     Arg::None},
     // {"lines", 'l'},                 
        {"debug",                       'd'},
        {"debug-step-skip",             's'},
        {"help",                        'h'},
        {"namespace",                   'n'},
        {"usage",                       'h'},
        {"verbose",                     'V'},
        {"version",                     'v'},
    };

    auto longEnd = longOptions +
                                sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("b:c:dhi:l:n:s::B:C:I:L:S:Vv",
                    longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, version, 1);

    States states;
    Rules rules(states);

    Parser parser(rules, states);
        parser.parse();

    if (Msg::errors())
        return 1;

    Ranges ranges(states);
        ranges.determineSubsets();
        ranges.finalizeStates();

    DFAs dfas(rules, states, ranges);
    dfas.build();

    cout << "RANGES:\n" << ranges << '\n' <<
            "RULES:\n" << rules << '\n' <<
            "STATES:\n" << states << '\n' <<
            dfas << '\n';

    Generator generator(rules, ranges, dfas);

        generator.lexSource();
        generator.baseclassHeader();
        generator.classHeader();
        generator.implementationHeader();

//        generator.declarations();
        generator.actions(dfas);
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
