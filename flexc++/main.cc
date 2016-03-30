#include "main.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        // options to set filenames

        // options setting filenames
                                                    // Options members also:
        Arg::LongOption{Options::baseclassHeaderSpec(),      'b'}, 

                                                    // used by Options::
                                                    // setAccessorVariables()
        Arg::LongOption{Options::classHeaderSpec(),          'c'}, 
        Arg::LongOption{Options::implementationHeaderSpec(), 'i'}, 

        Arg::LongOption{Options::lexSourceSpec(),      'l'},
        Arg::LongOption{"target-directory",            Arg::Required},
        Arg::LongOption{"filenames",                   'f'},

            // skeleton options             
        Arg::LongOption{"skeleton-directory",          'S'},
        Arg::LongOption{"baseclass-skeleton",          'B'},
        Arg::LongOption{"class-skeleton",              'C'},
        Arg::LongOption{"implementation-skeleton",     'I'},
        Arg::LongOption{"lex-skeleton",                'L'},

            // options preventing overwriting
        Arg::LongOption{"no-baseclass-header",         Arg::None},
        Arg::LongOption{"no-lex-source",               Arg::None},

        Arg::LongOption{"namespace",                   'n'},

        Arg::LongOption{"class-name",                  Arg::Required},
        Arg::LongOption{"lex-function-name",           Arg::Required},
        Arg::LongOption{"no-lines",                    Arg::None},

        Arg::LongOption{"help",                        'h'},
        Arg::LongOption{"usage",                       'h'},
        Arg::LongOption{"version",                     'v'},

        Arg::LongOption{"case-insensitive",            Arg::None},
        Arg::LongOption{"debug",                       'd'},
        Arg::LongOption{"construction",                'K'}, 
        Arg::LongOption{"matched-rules",               'R'},
        Arg::LongOption{"max-depth",                   'm'},
        Arg::LongOption{"print-tokens",                't'},
        Arg::LongOption{"own-parser",                  'P'},
        Arg::LongOption{"own-tokens",                  'T'},
        Arg::LongOption{"show-filenames",              'F'},
        Arg::LongOption{"verbose",                     'V'},
        Arg::LongOption{"regex-calls",                 Arg::None},
    };

    auto longEnd = longOptions +
                                sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("b:B:c:C:df:Fhi:I:Kl:L:m:n:PRS:TtvV",
                    longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, version, 1);

    DFA::setVerbose(arg.option('V'));

    States states;

    Rules rules(states);

    Parser parser(rules, states);

        if (parser.parse() != 0)
            return 1;

        parser.addLopStartConditions();
        parser.cleanup();

    rules.handleLopRules();

    Ranges ranges(states);
        ranges.determineSubsets();
        ranges.finalizeStates();

    DFAs dfas(rules, states, ranges);
        dfas.build();
        dfas.warnNonViable();

    Generator generator(rules, ranges, dfas);

    if (generator.conflicts())
    {
        wmsg << "Option/directive conflic(s): "
                    "no files were generated/modified" << endl;
        return 1;
    }

    generator.construction(states);

    if (rules.size() == 0)
        wmsg << "No regular expressions were defined: source files not "
                "generated" << endl;
    else
    {
        generator.lexSource();
        generator.baseclassHeader();
        generator.classHeader();
        generator.implementationHeader();
    }
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
