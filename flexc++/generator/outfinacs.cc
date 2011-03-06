#include "generator.ih"

void Generator::outFinAcs(vector<FinAcInfo> const &finAcs) 
{
    d_out << "\n"
        "    // The first value is the matched rule: >= 0 if a final state.\n"
        "    // The second value is the final/accept indicator:\n"
        "    // -2: this is not a final state, nor an accepting state\n"
        "    // -1: this is a final state, and all text is matched\n"
        "    // >= 0: This is an accepting state, and the value is the\n"
        "    //       current or initial tail length\n"
        "    // The third value indicates incrementing accept or not.\n"
        "    // If incrementing the actual tail length is incremented each\n"
        "    // time this state is reached again.\n"
        "    // The text CONFLICT is shown if a state is both accepting and\n"
        "    // final: this needs further investigation\n"
        "    FinAcInfo const ScannerBase::s_finAcInfo[] =\n"
        "    {\n"
        "           R FA  I\n";

    for_each(finAcs.begin(), finAcs.end(), FnWrap::unary(outFinAc, d_out));
   
    d_out << "    };\n";
}
