#include "generator.ih"

void Generator::dfas(DFAs const &dfas)
{
    d_out <<
    "\n"
    "    // s_dfa contain the rows of *all* DFAs ordered by start state.\n"
    "    // The enum class StartState is defined below. INITIAL is always 0\n"
    "    // Each row contains the row to transit to if the column's\n"
    "    // character range was sensed. Row numbers are relative to the\n"
    "    // used DFA. Following this a value != -1 indicates the rule for\n"
    "    // which this row is a FINAL state. The row's final two values are\n"
    "    // begin and end indices in s_accept, holding information about a\n"
    "    // row's accept state. -1 indicates `not an accept state'\n"
    "    //\n"
    "    size_t ScannerBase::s_dfa[][" << d_ranges.size() + 3 << "] =\n" 
    "    {\n";

    PVector accept;
    vector<string> startStates;
    vector<size_t>  dfaIndices(1, 0);

    auto iter = dfas.find("INITIAL");
    if (iter != dfas.end())
        dfa(*iter, d_out, accept, startStates, dfaIndices);

    for_each(dfas.begin(), dfas.end(), 
            FnWrap::unary(dfa, d_out, accept, startStates, dfaIndices));

    d_out << "   };\n";

    acceptStates(accept);
    dfaEntryPoints(dfaIndices);
}



