#include "generator.ih"

void Generator::dfas(ostream &out) const
{
    string const &className = d_options.className();

    out <<
    "int const " << className << "Base::s_dfa[][" << dfaCols() << "] =\n" 
    "{\n";

    auto iter = d_dfas.find("INITIAL");
    if (iter != d_dfas.end())
        dfa(*iter, out, d_finacs, d_startStates, d_dfaIndices);
 
    for_each(d_dfas.begin(), d_dfas.end(), 
            FnWrap::unary(dfa, out, d_finacs, d_startStates, d_dfaIndices));
 
    out << "};\n";
}



