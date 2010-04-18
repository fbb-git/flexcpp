#include "generator.ih"

void Generator::acceptStates(PVector const &accept) 
{
    d_out << "\n"
            "    ScannerBase::AcceptInfo const ScannerBase::s_accept[] =\n"
            "    {\n"
            "        ";

    size_t count = 0;
    for_each(accept.begin(), accept.end(), FnWrap::unary(outAccept, 
                                                         d_out, count));
   
    d_out << (count % 8 == 0 ? "" : "\n") << "    };\n";
}
