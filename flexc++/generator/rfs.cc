#include "generator.ih"

void Generator::rfs(ostream &out) const
{
    string const &className = d_options.className();

    out << 
        "size_t const " << className << "Base::s_rf__[][2] =\n"
        "{\n"
        "//     R  F\n";

    size_t idx = 0;

    for (auto &rf: d_rf)
        outRF(rf, out, idx);

    out << "};";
}
