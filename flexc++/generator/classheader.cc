#include "generator.ih"

// New members and other facilites may be added to the parser's class header
// after its initial generation. 

// Writing a base class header may be forced by the --force-class-header
// option. Otherwise, it's not rewritten by bisonc++ once it's available

void Generator::classHeader() const
{
    string const &classHeaderPath = d_options.classHeaderPath();
    
    if (Stat(classHeaderPath))
    {
        errExisting(classHeaderPath, "class-name",
                                "^class " + d_options.className() + "\\b");

        if (not d_options.nameSpace().empty())
            errExisting(classHeaderPath, "namespace",
                            "^namespace " + d_options.nameSpace() + "\\b");

        errExisting(classHeaderPath, Options::baseclassHeaderSpec(), 
                    "^#include \"" + d_options.baseclassHeaderName() + '"');

        return;
    }

    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.classSkeleton()); 
    Exception::open(out, classHeaderPath); 

    filter(in, out);    
}
