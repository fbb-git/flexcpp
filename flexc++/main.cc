#include "main.ih"

namespace 
{
    Arg::LongOption longOptions[] = 
    {
        // to be considered/implemented:

        Arg::LongOption("implementation-skeleton", 'I'),
        Arg::LongOption("skeleton-directory", 'S'),

        Arg::LongOption("lex-source", 'l'),

        Arg::LongOption("class-name", Arg::Required),

        Arg::LongOption("debug"),

        Arg::LongOption("filenames", 'f'),

        Arg::LongOption("force-implementation-header"),
        Arg::LongOption("force-class-header"),

        Arg::LongOption("namespace", 'n'),

        Arg::LongOption("no-lex-member"),

        Arg::LongOption("lines", 'l'),
        Arg::LongOption("no-lines"),

        Arg::LongOption("show-filenames"),
                // writes the names of the files to the standard output

        Arg::LongOption("thread-safe"),
                // no static data are modified, making bisonc++ thread-safe

        Arg::LongOption("verbose", 'V'),

        // available:

        Arg::LongOption("help", 'h'),

        Arg::LongOption("usage", 'h'),
        Arg::LongOption("version", 'v'),
    };

    Arg::LongOption const *const longEnd = longOptions + 
                                sizeof(longOptions) / sizeof(Arg::LongOption); 
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("f:hI:ln:s:S:Vv", 
                    longOptions, longEnd, argc, argv);

    arg.versionHelp(usage, version, 1);

    return 0;
}
catch (...)
{
    return 1;
}
