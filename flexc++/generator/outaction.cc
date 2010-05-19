#include "generator.ih"

void Generator::outAction(DFARow const &row, ostream &out, set<size_t> &done)
{
    for
    (
        auto iter = row.final().begin(), end = row.final().end();
        iter != end; ++iter
    )
    {
        if (done.find(*iter) != done.end())
            return;

        done.insert(*iter);
        out << "    case " << *iter << ":\n"
           "    {\n" <<
           "        " << row.action(*iter) << "\n"
           "    }\n"
           "    break;\n";
    }
}
