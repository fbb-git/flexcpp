#include "generator.ih"

void Generator::dfaEntryPoints(vector<size_t> const &dfaIndices)
{
    d_out << "\n"
            "    std:::unordered_map<ScannerBase::Begin, size_t (*)[" <<
                                                  dfaCols() << "]>\n"
            "    const ScannerBase::s_dfaHash =\n"
            "    {\n"
            "        ";

    transform(d_startStates.begin(), d_startStates.end(), dfaIndices.begin(),
            ostream_iterator<string>(d_out), outEntryPoint);
   
    d_out << "\n"
             "    };\n";
}
