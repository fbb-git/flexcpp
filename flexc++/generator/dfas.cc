#include "generator.ih"

void Generator::dfas(ostream &out) const
{
    string const &className = d_options.className();

    out <<
    "int const " << className << "Base::s_dfa__[][" << dfaCols() << "] =\n" 
    "{\n";

    // write the DFAs (INITIAL is always first, due to FBB::LinearMap)
    for(auto &dfaPair: d_dfas) 
        dfa(dfaPair, out, d_startStates, d_dfaIndices);
 
    out << "};\n";
}
