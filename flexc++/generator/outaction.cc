#include "generator.ih"

void Generator::outAction(DFARow const &row, ostream &out, set<size_t> &done)
{
    size_t final = row.final();

    if (done.find(final) != done.end())
        return;

    done.insert(final);
    out << "    case " << final << ":\n"
           "    {\n" <<
           "        " << row.action() << "\n"
           "    }\n";
}
