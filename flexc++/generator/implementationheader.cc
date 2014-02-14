#include "generator.ih"

// All members of the parser class should include the implementation header as
// the only #included file. The implementation header should perform all
// required preprocessor actions for the compilation of the Parser's class
// members

void Generator::implementationHeader() const
{
    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.implementationSkeleton()); 
    Exception::open(out, d_options.implementationHeaderPath());

    filter(in, out);    
}

