#include "generator.ih"

void Generator::acceptStates(PVector const &accept) 
{
    d_out << "\n"
            "    std::pair<char, size_t> s_accept[] =\n"
            "       {";

    size_t count = 0;
    for_each(accept.begin(), accept.end(), FnWrap::unary(outPair, 
                                                         d_out, count));
   
    d_out << (count % 8 == 0 ? "        " : "") << "};\n";
}
