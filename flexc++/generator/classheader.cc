#include "generator.ih"

// New members and other facilites may be added to the parser's class header
// after its initial generation. 

// Writing a base class header may be forced by the --force-class-header
// option. Otherwise, it's not rewritten by bisonc++ once it's available

void Generator::classHeader() const
{
    string const &classHeaderPath = d_options.classHeaderPath();
    
    if 
    (
        Stat(classHeaderPath)
        &&
        not d_options("force-class-header")
    )
    {
        warnExisting(classHeaderPath, "class-name", d_options.className(),
                                "^class " + d_options.className() + "\\b");

        if (not d_options.nameSpace().empty())
            warnExisting(classHeaderPath, "namespace", d_options.nameSpace(),
                            "^namespace " + d_options.nameSpace() + "\\b");

        warnExisting(classHeaderPath, Options::baseclassHeader(), 
                    d_options.baseclassHeaderName(), 
                    "^#include \"" + d_options.baseclassHeaderName() + '"');

        return;
    }

    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.classSkeleton()); 
    Exception::open(out, classHeaderPath); 

    filter(in, out);    
}
