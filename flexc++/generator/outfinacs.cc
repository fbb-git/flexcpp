#include "generator.ih"

void Generator::outFinAcs(vector<FinAcInfo> const &finAcs) 
{
    d_out << "\n"
    "    // The first value is the rule index\n"
    "    // The second value is the final indicator:\n"
    "    //  -2: not a final state, -1: final state, matching all text\n"
    "    //  >= 0: final state, the value is the LA tail length.\n"
    "    // The third value indicates other LA uses:\n"
    "    //  -1: Not a LA state tail length,\n"
    "    //  >=0: LA tail on transit FROM this state.\n"
    "    // The fourth value indicates an incrementing (1) tail:\n"
    "    // the tail length is incremented at each subsequent transition\n"
    "    //\n"
    "    FinAcInfo const ScannerBase::s_finAcInfo[] =\n"
    "    {\n"
    "           R  F  T  I\n";

    for_each(finAcs.begin(), finAcs.end(), FnWrap::unary(outFinAc, d_out));
   
    d_out << "    };\n";
}
