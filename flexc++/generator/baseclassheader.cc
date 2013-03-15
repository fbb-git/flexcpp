#include "generator.ih"

// Writing a base class header may be prevented by the --no-baseclass-header
// option. Otherwise, it's rewritten each time flexc++ is called to process a
// grammar. There should be no need for using the --no-baseclass-header 
// option, as all additional functionality can be defined in the
// scanner's class header.

void Generator::baseclassHeader() const
{
    if (d_options("no-baseclass-header"))
        return;

    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.baseclassSkeleton()); 
    Exception::open(out, d_options.baseclassHeaderPath()); 

    filter(in, out);    
}
