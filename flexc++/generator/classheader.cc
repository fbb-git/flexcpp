#include "generator.ih"

// New members and other facilites may be added to the parser's class header
// after its initial generation. 

// Writing a base class header may be forced by the --force-class-header
// option. Otherwise, it's not rewritten by bisonc++ once it's available

void Generator::classHeader() const
{
    if 
    (
        Stat(d_options.classHeaderPath())
        &&
        not d_options("force-class-header")
    )
        return;

    ofstream out;
    ifstream in;

    Errno::open(in,  d_options.classSkeleton()); 
    Errno::open(out, d_options.classHeaderPath()); 

    filter(in, out);    
}
