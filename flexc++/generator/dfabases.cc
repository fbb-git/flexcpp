#include "generator.ih"

void Generator::DFAbases(ostream &out) const
{
    string const &className = d_options.className();

    out << "\n"
            "int const (*" << className << "Base::s_dfaBase[])[24] =\n"
            "{\n";

    transform(d_startStates.begin(), d_startStates.end(), 
                d_dfaIndices.begin(), 
                ostream_iterator<string>(out, "\n"), outDFAbase);
   
    out << "};";
}
