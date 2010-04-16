#include "flexc++.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        // to be considered/implemented:

        // options to set filenames
        {"baseclassheader",         'b'},
        {"classheader",             'c'},
        {"implementationheader",    'i'},
        {"lexsource",               'l'},

        // skeleton options
        {"skeletondirectory",       'S'},
        {"baseclassskeleton",       'B'},
        {"classskeleton",           'C'},
        {"implementationskeleton",  'I'},
        {"lexskeleton",             'L'},

        // options to force overwriting
        Arg::LongOption("forceimplementationheader"),
        Arg::LongOption("forceclassheader"),

        {"namespace",               'n'},

        Arg::LongOption("classname"),       // TODO: to be implemented
        Arg::LongOption("lexfunctionname"), // TODO: to be implemented

        Arg::LongOption("nolexmember"),   // TODO: to be implemented

        Arg::LongOption("lines", 'l'),      // TODO: to be implemented

        Arg::LongOption("showfilenames"),  // TODO: to be implemented
                // writes the names of the files to the standard output

        {"nolines",                 Arg::None},
        {"tokens", 't'},

        // output options
        {"interactive",             Arg::None},
        {"dot",                     Arg::None},
        {"nfa",                     Arg::None},
        {"dfa",                     Arg::None},

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

    Ranges ranges(states);
        ranges.determineSubsets();
        ranges.finalizeStates();

    cout << "RANGES:\n" << ranges << '\n' <<
            "RULES:\n" << rules << '\n' <<
            "STATES:\n" << states << '\n';

    DFA dfa(ranges);
        dfa.build("INITIAL", rules, states);

    cout << "DFA INITIAL:\n" << dfa << '\n';
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