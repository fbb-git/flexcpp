#include "generator.ih"

void Generator::startCondInfo(ostream &out) const
{
    key(out);

    string const &scName = d_options.startConditionName();

                    // inserted in flexc++.cc

    out << 
"    // s_dfa__ contains the rows of *all* DFAs ordered by start state.  "
                                                                    "The\n"
"    // enum class " << scName << "is defined in the baseclass header.\n"
"    // " << scName << "::INITIAL is always 0.  "
                                            "Each entry defines the row to\n";
}
