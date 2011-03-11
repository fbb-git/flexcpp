#include "flexc++.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        // to be considered/implemented:

        // options to set filenames

        // options to set filenames
        {"baseclass-header",         'b'},
        {"class-header",             'c'},
        {"implementation-header",    'i'},
        {"lex-source",               'l'},

        // skeleton options
        {"skeleton-directory",       'S'},
        {"baseclass-skeleton",       'B'},
        {"class-skeleton",           'C'},
        {"implementation-skeleton",  'I'},
        {"lex-skeleton",             'L'},


        // options to force overwriting
        Arg::LongOption("force-implementation-header"),
        Arg::LongOption("force-class-header"),
        Arg::LongOption("no-baseclass-header"),
        Arg::LongOption("no-lex-member"),

        {"namespace",               'n'},

        Arg::LongOption("class-name", Arg::Required),
        Arg::LongOption("lex-function-name", Arg::Required),

        Arg::LongOption("no-lex-member"),

    // Arg::LongOption("lines", 'l'),      // TODO: to be implemented

        Arg::LongOption("show-filenames"),
                // writes the names of the files to the standard output

    //    {"nolines",                 Arg::None},
        {"tokens", 't'},

        {"verbose",                 'V'},
        {"debug",                   'd'},

        // Miscellaneous options
        {"help",                    'h'},
        {"usage",                   'h'},
        {"version",                 'v'},
    };

    //Arg::LongOption const *const 
    auto longEnd = longOptions +
                                sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("df:hI:B:C:L:S:b:c:i:l:n:s:tVv",
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
//        generator.actions(dfas);
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
