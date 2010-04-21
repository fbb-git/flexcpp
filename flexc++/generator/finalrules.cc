#include "generator.ih"

void Generator::finalRules(vector<size_t> const &final) 
{
    d_out << "\n"
            "    size_t const ScannerBase::s_final[] =\n"
            "    {\n"
            "        ";

    size_t count = 0;
    for_each(final.begin(), final.end(), FnWrap::unary(outFinal, 
                                                         d_out, count));
   
    d_out << (count % 20 == 0 ? "" : "\n") << "    };\n";
}
