#include "generator.ih"

void Generator::dfaEntryPoints(vector<size_t> const &dfaIndices)
{
    d_out << "\n"
            "    std::unordered_map<ScannerBase::Begin, int const (*)[" <<
                                                  dfaCols() << "],\n"
            "                       ScannerBase::HashBegin> const "
                                                "ScannerBase::s_dfaHash =\n"
            "    {\n";

    transform(d_startStates.begin(), d_startStates.end(), dfaIndices.begin(),
            ostream_iterator<string>(d_out, "\n"), outEntryPoint);
   
    d_out << "    };\n";
}
