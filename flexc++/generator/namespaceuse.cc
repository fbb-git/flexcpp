#include "generator.ih"

void Generator::namespaceUse(ostream &out) const
{
    if (d_options.nameSpace().empty())
        return;

    key(out);
    out <<  
    "    // UN-comment the next using-declaration if you want to use\n"
    "    // symbols from the namespace " << d_options.nameSpace() << 
                  " without prefixing " << d_options.nameSpace() << "::\n"
    "//using namespace " << d_options.nameSpace() << ";\n";
}
