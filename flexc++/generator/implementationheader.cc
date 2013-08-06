#include "generator.ih"

// All members of the parser class should include the implementation header as
// the only #included file. The implementation header should perform all
// required preprocessor actions for the compilation of the Parser's class
// members

// Writing an implementation header header may be forced by the
// --force-implementation-header option. Otherwise, it's not rewritten by
// bisonc++ once it's available

void Generator::implementationHeader() const
{
    string const &implementationHeader = d_options.implementationHeaderPath();

    if 
    (
        Stat(implementationHeader)
        &&
        not d_options("force-implementation-header")
    )
    {
        warnExisting(implementationHeader, d_options.classHeaderPath(), 
                        d_options.classHeaderName(),
                        "^#include \"" + d_options.classHeaderName() + '"');
        return;
    }

    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.implementationSkeleton()); 
    Exception::open(out, implementationHeader); 

    filter(in, out);    
}

