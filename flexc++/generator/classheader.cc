#include "generator.ih"

// New members and other facilites may be added to the parser's class header
// after its initial generation. 

void Generator::classHeader() const
{
    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.classSkeleton()); 
    Exception::open(out, d_options.classHeaderPath()); 

    filter(in, out);    
}
