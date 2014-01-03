#include "generator.ih"

void Generator::dfas(ostream &out) const
{
    string const &className = d_options.className();

    out <<
    "int const " << className << "Base::s_dfa__[][" << dfaCols() << "] =\n" 
    "{\n";

    auto iter = d_dfas.find("INITIAL");
    if (iter != d_dfas.end())
        dfa(*iter, out, d_rf, d_startStates, d_dfaIndices);

    for(auto &dfaPair: d_dfas) 
        dfa(dfaPair, out, d_rf, d_startStates, d_dfaIndices);
 
    out << "};\n";
}
