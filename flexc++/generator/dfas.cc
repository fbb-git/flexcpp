#include "generator.ih"

void Generator::dfas(ostream &out) const
{
    string const &className = d_options.className();

    out <<
    "int const " << className << "Base::s_dfa__[][" << dfaCols() << "] =\n" 
    "{\n";

    // write the DFAs: INITIAL is first, because FBB::LinearMap is used.
    for(auto &dfaPair: d_dfas) 
        dfa(dfaPair, out, d_startStates, d_dfaIndices);
 
    out << "};\n";
}
