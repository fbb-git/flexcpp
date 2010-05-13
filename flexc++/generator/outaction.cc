#include "generator.ih"

void Generator::outAction(DFARow const &row, ostream &out, set<size_t> &done)
{
//X    for
//X    (
//X        auto iter = row.final().begin(), end = row.final().end();
//X        iter != end; ++iter
//X    )
//X    {
//X        if (done.find(*iter) != done.end())
//X            return;
//X
//X        done.insert(*iter);
//X        out << "    case " << *iter << ":\n"
//X           "    {\n" <<
//X           "        " << row.action(*iter) << "\n"
//X           "    }\n"
//X           "    break;\n";
//X    }
}
