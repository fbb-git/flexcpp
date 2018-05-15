#include "generator.ih"

    // see also: insert.cc

void Generator::debug(ostream &out) const
{
    if (not debugTest())
        return;

    key(out);

    out << indent << "if (s_debug_)\n" <<
           indent << "    " << flush;

    if (*d_line.rbegin() != '+')
        out <<  "s_out_ << " << d_line << " << \"\\n\" << dflush_;\n";
    else
    {
        d_line.resize(d_line.length() - 1);
        out <<  "s_out_ << " << d_line << ";\n";
    }
}
