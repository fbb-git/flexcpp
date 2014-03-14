#include "generator.ih"

// New members and other facilites may be added to the parser's class header
// after its initial generation. 

void Generator::classHeader() const
{
    string const &classHeaderPath = d_options.classHeaderPath();

    if (Stat(classHeaderPath))
        return;

    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.classSkeleton()); 
    Exception::open(out, classHeaderPath); 

    filter(in, out);    
}
