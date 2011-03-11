#include "generator.ih"

void Generator::dfas(ostream &out) const
{
    string const &className = d_options.className();

    out <<
    "\n"
    "// s_dfa contains the rows of *all* DFAs ordered by start state.\n"
    "// The enum class StartCondition is defined in the baseclass "
                                                                "header\n"
    "// INITIAL is always 0.\n"
    "// Each entry defines the row to transit to if the column's\n"
    "// character range was sensed. Row numbers are relative to the\n"
    "// used DFA and d_dfaBase is set to the first row of the subset to "
                                                                "use.\n"
    "// The row's final two values are begin and end indices in\n"
    "// s_accept[], defining the state's final and LA details\n"

    "//\n"
    "int const " << className << "Base::s_dfa[][" << dfaCols() << "] =\n" 
    "{\n";

    auto iter = d_dfas.find("INITIAL");
    if (iter != d_dfas.end())
        dfa(*iter, out, d_finacs, d_startStates, d_dfaIndices);
 
    for_each(d_dfas.begin(), d_dfas.end(), 
            FnWrap::unary(dfa, out, d_finacs, d_startStates, d_dfaIndices));
 
    out << "};";
}



