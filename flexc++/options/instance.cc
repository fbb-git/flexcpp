#include "options.hh"

Options &Options::instance()
{
    if (s_options == 0)
        s_options = new Options();  
                                    // yes, it exists until the program ends
                                    // and memory is claimed back by the
                                    // operaring system
    return *s_options;
}
