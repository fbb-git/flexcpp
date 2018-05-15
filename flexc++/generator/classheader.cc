#include "generator.ih"

// New members and other facilites may be added to the parser's class header
// after its initial generation. 

void Generator::classHeader() const
{
    string const &classHeaderPath = d_options.classHeaderPath();

    if (Stat(classHeaderPath))
    {
        if (not grep(classHeaderPath, 
          R"(void[[:blank:]]+postCode[[:blank:]]*\([[:blank:]]*PostEnum_)" ))
            wmsg << "`void postCode' not found in " << 
                                                    classHeaderPath << ".\n"
                "       Advice: add the following member to the private "
                                                        "section of the\n"
                "       scanner class in " << classHeaderPath << 
                                                " (cf.: man 3 flexc++api):\n"
                "           void postCode(PostEnum_)\n"
                "           {}\n" <<
                endl;

        return;
    }

    ofstream out;
    ifstream in;

    Exception::open(in,  d_options.classSkeleton()); 
    Exception::open(out, classHeaderPath); 

    filter(in, out);    
}
