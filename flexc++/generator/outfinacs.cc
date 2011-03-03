#include "generator.ih"

void Generator::outFinAcs(vector<FinAcInfo> const &finAcs) 
{
    d_out << "\n"
            "    FinAcInfo const ScannerBase::s_finAcInfo[] =\n"
            "    {\n"
            "           R  F  A  I\n";

    for_each(finAcs.begin(), finAcs.end(), FnWrap::unary(outFinAc, d_out));
   
    d_out << "    };\n";
}
