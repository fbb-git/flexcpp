#include "parser.hh"

void Parser::cleanup()
{
    emsg.setTag("error");

    wmsg.setTag("Warning");
    wmsg.noLineNr();

    d_options.setAccessorVariables();

    // bisonc++ calls d_options.setVerbosity(); here

    d_options.setPathStrings();

    if (int count = emsg.count())   // Terminate if parsing produced errors. 
    {
        cout << "Error(s): " << count << '\n';
        throw 1;
    }

    d_options.showFilenames();
                            // shows the verbosity-filename, otherwise 
                            // independent of the verbosity setting
}




