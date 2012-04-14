#include "options.ih"

Options &Options::init(Arg const &arg)
{
    if (s_options == 0)
        s_options = new Options(arg);  
                                    // yes, it exists until the program ends
                                    // and memory is claimed back by the
                                    // operaring system
    return *s_options;
}
